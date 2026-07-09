#include "firmware.h"
#include "uart.h"
#include "tusb.h"
#include <stdarg.h>

// Initialize USB UART
void uartInitUsb() {
    tusb_rhport_init_t dev_init = {
        .role = TUSB_ROLE_DEVICE,
        .speed = TUSB_SPEED_AUTO
    };

    tusb_init(BOARD_TUD_RHPORT, &dev_init);

    uint32_t start = to_ms_since_boot(get_absolute_time());

    while (!tud_cdc_connected()) { // Wait for USB to be ready
        tud_task();

        if (to_ms_since_boot(get_absolute_time()) - start > 1000) {
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

    tud_task();

    if (!tud_cdc_available()) {
        return false;
    }

    uint32_t start = to_ms_since_boot(get_absolute_time());

    while (i < max_len - 1) {
        int c = -1;
        
        if (tud_cdc_available()) {
            c = tud_cdc_read_char();
            start = to_ms_since_boot(get_absolute_time());
        }

        if (c == -1) { // No character available
            if (to_ms_since_boot(get_absolute_time()) - start > 1000)
            {
                break;
            }

            continue;
        }

        if (c == '\n' || c == '\r') { // End of line
            break;
        }

        if (c < 0x20 || c > 0x7E) { // Ignore non-printable characters
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

// Handle command: read <addrstart> [addrend]
static void cmdRead(char *args) {
    char *token = strtok(args, " ");

    if (token == NULL) {
        serialprintf("ERROR: missing address\n");

        return;
    }

    uint16_t addr_start;

    if (!parseHex16(token, &addr_start)) {
        serialprintf("ERROR: invalid address '%s'\n", token);

        return;
    }

    uint16_t addr_end = addr_start;
    token = strtok(NULL, " ");

    if (token != NULL) {
        if (!parseHex16(token, &addr_end)) {
            serialprintf("ERROR: invalid end address '%s'\n", token);

            return;
        }

        if (addr_end < addr_start) {
            serialprintf("ERROR: end address must be >= start address\n");

            return;
        }
    }

    for (uint16_t addr = addr_start; ; addr++) {
        accessRamAddress(addr);

        uint8_t val = readRamCell();

        serialprintf("%02X", val);

        if (addr == addr_end) {
            break;
        }

        serialprintf(" ");
    }

    serialprintf("\n");
}

// Handle command: write <addr> <value>
static void cmdWrite(char *args) {
    char *token = strtok(args, " ");

    if (token == NULL) {
        serialprintf("ERROR: missing address\n");

        return;
    }

    uint16_t addr;

    if (!parseHex16(token, &addr)) {
        serialprintf("ERROR: invalid address '%s'\n", token);

        return;
    }

    token = strtok(NULL, " ");

    if (token == NULL) {
        serialprintf("ERROR: missing value\n");

        return;
    }

    uint8_t val;

    if (!parseHex8(token, &val)) {
        serialprintf("ERROR: invalid value '%s'\n", token);

        return;
    }

    accessRamAddress(addr);
    writeRamCell(val);

    // Read back to confirm
    accessRamAddress(addr);

    uint8_t readback = readRamCell();

    serialprintf("%02X\n", readback);
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
            serialprintf("ERROR: invalid argument '%s'\n", args);
        }
    }
}

// Handle command: help
static void cmdHelp(char *args) {
    serialprintf("Available commands:\n");
    serialprintf("\tread <addrstart> [addrend] - Read bytes from RAM, from a single address or from a range.\n");
    serialprintf("\twrite <addr> <value> - Write a byte to RAM in the given address.\n");
    serialprintf("\tlogs [on/off] - Turn on or off the logs. If no argument is provided, the logs will be toggled.\n");
    serialprintf("\thelp - Show this help message.\n");
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
    else if (strcmp(verb, "help") == 0) {
        cmdHelp(args);
    }
    else {
        serialprintf("ERROR: unknown command '%s'\n", verb);
    }
}
