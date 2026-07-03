#include "firmware.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#ifndef Z80DEVBOARD_UART
    #define Z80DEVBOARD_UART

    #define UART_CMD_MAX_LEN 64

    // UART variables
    extern bool showLogs; // Flag to check if the logs are enabled by the user
 
    // UART functions
    void uartInitUsb();
    bool uartReadLine(char *buf, size_t max_len);
    void uartProcessCommand(const char *cmd);
#endif
