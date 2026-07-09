#include "firmware.h"
#include "uart.h"
#include "mscDisk.h"
#include "tusb.h"
#include <stdlib.h>

bool wasSerialConnected = false;
bool showLogs = false;

// Send a bus request to the Z80 and wait for the bus acknowledgment.
bool sendBusReqAndWaitBusAck() {
    if (gpio_get(GPIO_Z80_BUSACK) == 0) {
        // BUSREQ already sended and BUSACK already received
        showLogs?serialprintf("[LOG] Received BUSACK.\n"):null;

        return true;
    }

    showLogs?serialprintf("[LOG] Sending BUSREQ.\n"):null;
    showLogs?serialprintf("[INFO] Remember to send a clock signal to the Z80!\n"):null;
    gpio_put(GPIO_Z80_BUSREQ, 0);

    uint32_t start = to_ms_since_boot(get_absolute_time());

    showLogs?serialprintf("[LOG] Awaiting BUSACK.\n"):null;
    
    while (gpio_get(GPIO_Z80_BUSACK) != 0) {
        if (to_ms_since_boot(get_absolute_time()) - start > 3000) {
            showLogs?serialprintf("[ERROR] BUSACK timeout\n"):null;

            releaseBusReq();
            
            return false;
        }
    }

    showLogs?serialprintf("[LOG] Received BUSACK.\n"):null;

    return true;
}

// Release the bus request to the Z80.
bool releaseBusReq() {
    showLogs?serialprintf("[LOG] Releasing BUSREQ.\n"):null;
    
    gpio_put(GPIO_Z80_BUSREQ, 1);

    return true;
}

// Access the RAM at the given address.
bool accessRamAddress(uint16_t address) {
    if (!sendBusReqAndWaitBusAck()) {
        return false;
    }

    for (int i = 15; i >= 0; i--)
    {
        gpio_put(GPIO_RAM_ADDRESS, ((address >> i) & 1));
        gpio_put(GPIO_SHIFT_CLOCK, 1);
        gpio_put(GPIO_SHIFT_CLOCK, 0);
    }

    return true;
}

// Read a byte from the RAM.
uint8_t readRamCell() {
    uint8_t data = 0;

    if (!sendBusReqAndWaitBusAck()) {
        return 0;
    }

    gpio_put(GPIO_RAM_OPERATION, 0);
    sleep_us(1); // Wait for the RAM to prepare the data

    for (int i = 7; i >= 0; i--)
    {
        data |= (gpio_get(GPIO_RAM_DATA_READ) << i);
        gpio_put(GPIO_RAM_DATA_SHIFT, 1);
        gpio_put(GPIO_RAM_DATA_SHIFT, 0);
    }

    return data;
}

// Write a byte to the RAM.
bool writeRamCell(uint8_t data) {
    if (!sendBusReqAndWaitBusAck()) {
        return false;
    }

    gpio_put(GPIO_RAM_OPERATION, 1);
    sleep_us(1); // Wait for the RAM to prepare the data

    for (int i = 7; i >= 0; i--)
    {
        gpio_put(GPIO_RAM_DATA, ((data >> i) & 1));
        gpio_put(GPIO_SHIFT_CLOCK, 1);
        gpio_put(GPIO_SHIFT_CLOCK, 0);
    }

    return true;
}

// Reset the Z80 to start executing the program loaded in the RAM.
void resetZ80() {
    gpio_put(GPIO_Z80_RESET, 0);
    sleep_ms(100);
    gpio_put(GPIO_Z80_RESET, 1);
}

// Read the Z80 program from the USB to the RAM.
void readZ80ProgramFromUsb(uint8_t *prog_buf) {
    mscDiskInit();

    showLogs?serialprintf("[LOG] MSC disk ready.\n"):null;
    showLogs?serialprintf("[INFO] Copy PROGRAM.BIN on the Z80DevBoard drive.\n"):null;

    // Wait for the disk to be written
    while (!mscDiskWritten()) {
        tud_task(); // Handle USB events
        sleep_ms(10);
    }

    sleep_ms(500); // Wait for the disk to be written completely
    
    mscDiskRead(prog_buf);

    showLogs?serialprintf("[LOG] Program received from USB disk.\n"):null;
}

// Load the Z80 program from the USB to the flash memory.
void Z80ProgramLoadHandler() {
    uint8_t *prog_buf = malloc(FLASH_LAST_32K_SIZE);

    readZ80ProgramFromUsb(prog_buf);
    
    saveZ80ProgramInFlash(prog_buf);

    free(prog_buf);

    resetZ80();
}

// Load the Z80 program from the flash memory to the RAM.
void loadZ80ProgramInRam() {
    uint8_t *ram_buf = malloc(FLASH_LAST_32K_SIZE);

    loadZ80ProgramFromFlash(ram_buf);

    for (uint32_t i = 0; i < FLASH_LAST_32K_SIZE; i++)
    {
        uint8_t data = ram_buf[i];

        if (!accessRamAddress((uint16_t)i)) {
            break;
        }

        if (!writeRamCell(data)) {
            break;
        }
    }

    free(ram_buf);

    releaseBusReq();
    resetZ80();
}

// Print the serial banner to the USB terminal.
void printSerialBanner() {
    serialprintf("+---------------------------------+\n");
    serialprintf("|           Z80DevBoard           |\n");
    serialprintf("|                                 |\n");
    serialprintf("|        Official Firmware        |\n");
    serialprintf("|         Serial Terminal         |\n");
    serialprintf("+---------------------------------+\n\n");
}

void serialprintf(const char *format, ...) {
    char buf[256];
    va_list args;

    va_start(args, format);

    int len = vsnprintf(buf, sizeof(buf), format, args);

    va_end(args);

    tud_cdc_write(buf, len);
    tud_cdc_write_flush();
}

/* 
    This function is runned only once at the start of the program.
*/
void setup() {
    // Initialize the GPIO pins
    gpio_init(GPIO_Z80_PROGRAM_LOAD);
    gpio_set_dir(GPIO_Z80_PROGRAM_LOAD, GPIO_IN);
    gpio_init(GPIO_RAM_ADDRESS);
    gpio_set_dir(GPIO_RAM_ADDRESS, GPIO_OUT);
    gpio_init(GPIO_RAM_DATA);
    gpio_set_dir(GPIO_RAM_DATA, GPIO_OUT);
    gpio_init(GPIO_SHIFT_CLOCK);
    gpio_set_dir(GPIO_SHIFT_CLOCK, GPIO_OUT);
    gpio_init(GPIO_RAM_OPERATION);
    gpio_set_dir(GPIO_RAM_OPERATION, GPIO_OUT);
    gpio_init(GPIO_Z80_RESET);
    gpio_set_dir(GPIO_Z80_RESET, GPIO_OUT); // Default to output, but will be used also as input
    gpio_init(GPIO_RAM_DATA_READ);
    gpio_set_dir(GPIO_RAM_DATA_READ, GPIO_IN);
    gpio_init(GPIO_RAM_DATA_SHIFT);
    gpio_set_dir(GPIO_RAM_DATA_SHIFT, GPIO_OUT);
    gpio_init(GPIO_Z80_BUSREQ);
    gpio_set_dir(GPIO_Z80_BUSREQ, GPIO_OUT);
    gpio_init(GPIO_Z80_BUSACK);
    gpio_set_dir(GPIO_Z80_BUSACK, GPIO_IN);

    // Expansion pins - decomment for use. Must be commented if not used.
    /* gpio_init(GPIO_EXPANSION_1);
    gpio_set_dir(GPIO_EXPANSION_1, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_2);
    gpio_set_dir(GPIO_EXPANSION_2, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_3);
    gpio_set_dir(GPIO_EXPANSION_3, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_4);
    gpio_set_dir(GPIO_EXPANSION_4, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_5);
    gpio_set_dir(GPIO_EXPANSION_5, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_6);
    gpio_set_dir(GPIO_EXPANSION_6, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_7);
    gpio_set_dir(GPIO_EXPANSION_7, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_8);
    gpio_set_dir(GPIO_EXPANSION_8, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_9);
    gpio_set_dir(GPIO_EXPANSION_9, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_10);
    gpio_set_dir(GPIO_EXPANSION_10, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_11);
    gpio_set_dir(GPIO_EXPANSION_11, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_12);
    gpio_set_dir(GPIO_EXPANSION_12, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_13);
    gpio_set_dir(GPIO_EXPANSION_13, GPIO_OUT);
    gpio_init(GPIO_EXPANSION_14);
    gpio_set_dir(GPIO_EXPANSION_14, GPIO_OUT); */

    gpio_put(GPIO_Z80_BUSREQ, 1);
    gpio_put(GPIO_Z80_RESET, 1);
    gpio_put(GPIO_SHIFT_CLOCK, 0);
    gpio_put(GPIO_RAM_OPERATION, 0);

    uartInitUsb();

    bool connectedSerial = tud_cdc_connected();
    
    if (connectedSerial && !wasSerialConnected) {
        printSerialBanner();
    }

    wasSerialConnected = connectedSerial;

    if (gpio_get(GPIO_Z80_PROGRAM_LOAD) == 0) {
        wasSerialConnected?serialprintf("[SYSTEM] Z80 New Program Loading...\n"):null;

        Z80ProgramLoadHandler();

        wasSerialConnected?serialprintf("[SYSTEM] New Z80 Program Loaded!\n"):null;
    }

    wasSerialConnected?serialprintf("[SYSTEM] Loading Z80 Program in RAM...\n"):null;

    loadZ80ProgramInRam();

    wasSerialConnected?serialprintf("[SYSTEM] Z80 Program Loaded in RAM!\n"):null;
}

/* 
    This function is runned in a loop after the setup function.
*/
void loop() {
    tud_task();

    // Check if the USB terminal is connected
    bool connectedSerial = tud_cdc_connected();

    if (connectedSerial && !wasSerialConnected) {
        printSerialBanner();
    }

    wasSerialConnected = connectedSerial;

    // Check if a command is received from the USB terminal
    char cmd[UART_CMD_MAX_LEN];

    if (uartReadLine(cmd, sizeof(cmd))) {
        serialprintf("> %s\n", cmd);

        uartProcessCommand(cmd);
    }
    else {
        sleep_ms(10);
    }
}
