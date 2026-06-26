#include "firmware.h"
#include "uart.h"
#include <stdlib.h>

// Send a bus request to the Z80 and wait for the bus acknowledgment.
bool sendBusReqAndWaitBusAck() {
    if (gpio_get(GPIO_Z80_BUSACK) == 0) {
        // BUSREQ already sended and BUSACK already received
        return true;
    }

    gpio_put(GPIO_Z80_BUSREQ, 0);

    while (gpio_get(GPIO_Z80_BUSACK) != 0) {
        // Wait for the Z80 to acknowledge the bus request
    }

    return true;
}

// Release the bus request to the Z80.
bool releaseBusReq() {
    gpio_put(GPIO_Z80_BUSREQ, 1);

    return true;
}

// Access the RAM at the given address.
void accessRamAddress(uint32_t address) {
    sendBusReqAndWaitBusAck();
    
    for (int i = 15; i >= 0; i--)
    {
        gpio_put(GPIO_RAM_ADDRESS, ((address >> i) & 1));
        gpio_put(GPIO_SHIFT_CLOCK, 1);
        gpio_put(GPIO_SHIFT_CLOCK, 0);
    }
}

// Read a byte from the RAM.
uint8_t readRamCell() {
    uint8_t data = 0;

    sendBusReqAndWaitBusAck();

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
void writeRamCell(uint8_t data) {
    sendBusReqAndWaitBusAck();

    gpio_put(GPIO_RAM_OPERATION, 1);
    sleep_us(1); // Wait for the RAM to prepare the data

    for (int i = 7; i >= 0; i--)
    {
        gpio_put(GPIO_RAM_DATA, ((data >> i) & 1));
        gpio_put(GPIO_SHIFT_CLOCK, 1);
        gpio_put(GPIO_SHIFT_CLOCK, 0);
    }
}

// Reset the Z80 to start executing the program loaded in the RAM.
void resetZ80() {
    gpio_put(GPIO_Z80_RESET, 0);
    sleep_ms(100);
    gpio_put(GPIO_Z80_RESET, 1);
}

void Z80ProgramLoadHandler() {
    uint8_t *prog_buf = malloc(FLASH_LAST_32K_SIZE);

    sendBusReqAndWaitBusAck();

    // TODO: readZ80ProgramFromUsb(prog_buf);
    saveZ80ProgramInFlash(prog_buf);

    free(prog_buf);

    releaseBusReq();
    resetZ80();
}

// Load the Z80 program from the flash memory to the RAM.
void loadZ80ProgramInRam() {
    uint8_t *ram_buf = malloc(FLASH_LAST_32K_SIZE);

    loadZ80ProgramFromFlash(ram_buf);

    for (uint32_t i = 0; i < FLASH_LAST_32K_SIZE; i++)
    {
        uint8_t data = ram_buf[i];

        accessRamAddress(i);
        writeRamCell(data);
    }

    free(ram_buf);

    releaseBusReq();
    resetZ80();
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
    
    if (gpio_get(GPIO_Z80_PROGRAM_LOAD) == 1) {
        Z80ProgramLoadHandler();
    }

    loadZ80ProgramInRam();
}

/* 
    This function is runned in a loop after the setup function.
*/
void loop() {
    char cmd[UART_CMD_MAX_LEN];

    if (uartReadLine(cmd, sizeof(cmd))) {
        uartProcessCommand(cmd);
    }
}
