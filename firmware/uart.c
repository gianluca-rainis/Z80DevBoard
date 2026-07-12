#include "firmware.h"
#include "uart.h"
#include "tusb.h"
#include <stdarg.h>

// Initialize USB UART
void uartInitUsb() {
    stdio_init_all();

    uint32_t start = to_ms_since_boot(get_absolute_time());

    while (!stdio_usb_connected()) {
        if (to_ms_since_boot(get_absolute_time()) - start > 3000)
        {
            break;
        }

        sleep_ms(10);
    }

    sleep_ms(100);
}

// Read a line from USB UART
bool uartReadLine(char *buf, size_t max_len) {
    size_t i = 0;

    if (max_len == 0) {
        return false;
    }

    while (i < max_len - 1) {
        int c = getchar_timeout_us(i == 0 ? 0 : 100000);

        if (c == PICO_ERROR_TIMEOUT) {
            if (i == 0)
            {
                return false;
            }
            
            continue;
        }

        if (c == '\n' || c == '\r')
        {
            break;
        }

        if (c < 0x20 || c > 0x7E)
        {
            continue;
        }

        buf[i++] = (char)c;
    }

    buf[i] = '\0';

    return i > 0; // Return true if we read any characters
}

// Parse a hex string (0xXXXX) into a uint16_t.
static bool parseHex16(const char *str, uint16_t *out) {
    char *end;
    unsigned long val = strtoul(str, &end, 16);

    if (end == str || val > 0xFFFF) {
        return false;
    }

    *out = (uint16_t)val;

    return true;
}

// Parse a hex string (0xXX) into a uint8_t.
static bool parseHex8(const char *str, uint8_t *out) {
    char *end;
    unsigned long val = strtoul(str, &end, 16);

    if (end == str || val > 0xFF) {
        return false;
    }

    *out = (uint8_t)val;

    return true;
}

// Check for the "--force" flag in the command
static bool extractForce(char *args) {
    if (args == NULL)
    {
        return false;
    }

    char *pos = strstr(args, "--force");

    if (pos == NULL)
    {
        return false;
    }

    for (int i = 0; i < 7; i++)
    {
        pos[i] = ' ';
    }

    return true;
}

// Handle command: read <addrstart> [addrend]
static void cmdRead(char *args) {
    bool force = extractForce(args);
    char *token = strtok(args, " ");

    if (token == NULL) {
        printf("ERROR: missing address\n");

        return;
    }

    uint16_t addr_start;

    if (!parseHex16(token, &addr_start)) {
        printf("ERROR: invalid address '%s'\n", token);

        return;
    }

    uint16_t addr_end = addr_start;
    token = strtok(NULL, " ");

    if (token != NULL) {
        if (!parseHex16(token, &addr_end)) {
            printf("ERROR: invalid end address '%s'\n", token);

            return;
        }

        if (addr_end < addr_start) {
            printf("ERROR: end address must be >= start address\n");

            return;
        }
    }

    force?printf("[WARNING] Force flag detected. Forcing reading of RAM. Remember that this operation can cause unexpected behavior!\n"):null;

    for (uint16_t addr = addr_start; ; addr++) {
        accessRamAddress(addr, force);

        uint8_t val = readRamCell(force);

        printf("%02X", val);

        if (addr == addr_end) {
            break;
        }

        printf(" ");
    }

    printf("\n");
}

// Handle command: write <addr> <value>
static void cmdWrite(char *args) {
    bool force = extractForce(args);
    char *token = strtok(args, " ");

    if (token == NULL) {
        printf("ERROR: missing address\n");

        return;
    }

    uint16_t addr;

    if (!parseHex16(token, &addr)) {
        printf("ERROR: invalid address '%s'\n", token);

        return;
    }

    token = strtok(NULL, " ");

    if (token == NULL) {
        printf("ERROR: missing value\n");

        return;
    }

    uint8_t val;

    if (!parseHex8(token, &val)) {
        printf("ERROR: invalid value '%s'\n", token);

        return;
    }

    force?printf("[WARNING] Force flag detected. Forcing writing of the given value in RAM. Remember that this operation can cause unexpected behavior!\n"):null;

    accessRamAddress(addr, force);
    writeRamCell(val, force);

    // Read back to confirm
    accessRamAddress(addr, force);

    uint8_t readback = readRamCell(force);

    printf("%02X\n", readback);
}

// Toggle the showLogs flag
static void cmdLogs(char *args) {
    if (args == NULL) {
        showLogs = !showLogs;
    }
    else {
        if (strcmp(args, "on") == 0) {
            showLogs = true;
        }
        else if (strcmp(args, "off") == 0) {
            showLogs = false;
        }
        else {
            printf("ERROR: invalid argument '%s'\n", args);
        }
    }
}

// Handle command: reload
static void cmdZ80ProgramReload(char *args) {
    bool force = extractForce(args);
    char *token = strtok(args, " ");

    showLogs?printf("[LOG] Reloading Z80 program in RAM...\n"):null;

    force?printf("[WARNING] Force flag detected. Forcing reload of Z80 program in RAM. Remember that this operation can cause unexpected behavior!\n"):null;

    loadZ80ProgramInRam(force);

    showLogs?printf("[LOG] Reload Z80 program in RAM completed.\n"):null;
}

// Handle command: help
static void cmdHelp(char *args) {
    printf("Available commands:\n");
    printf("\tread <addrstart> [addrend] [--force] - Read bytes from RAM, from a single address or from a range.\n");
    printf("\twrite <addr> <value> [--force] - Write a byte to RAM in the given address.\n");
    printf("\tlogs [on/off] - Turn on or off the logs. If no argument is provided, the logs will be toggled.\n");
    printf("\treload [--force] - Reload the Z80 program in RAM.\n");
    printf("\thelp - Show this help message.\n");
}

// Dispatch a command string to the appropriate handler.
void uartProcessCommand(const char *cmd) {
    // Make a mutable copy to allow strtok
    char buf[UART_CMD_MAX_LEN];

    strncpy(buf, cmd, UART_CMD_MAX_LEN - 1);

    buf[UART_CMD_MAX_LEN - 1] = '\0';

    char *verb = strtok(buf, " ");

    if (verb == NULL || verb[0] == '\0') {
        return; // Ignore empty line
    }

    char *args = strtok(NULL, "");

    if (strcmp(verb, "read") == 0) {
        cmdRead(args);
    }
    else if (strcmp(verb, "write") == 0) {
        cmdWrite(args);
    }
    else if (strcmp(verb, "logs") == 0) {
        cmdLogs(args);
    }
    else if (strcmp(verb, "reload") == 0) {
        cmdZ80ProgramReload(args);
    }
    else if (strcmp(verb, "help") == 0) {
        cmdHelp(args);
    }
    else {
        printf("ERROR: unknown command '%s'\n", verb);
    }
}
