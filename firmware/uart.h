#include "firmware.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#ifndef UART
    #define UART

    #define UART_CMD_MAX_LEN 64
 
    // UART functions
    void uartInitUsb();
    bool uartReadLine(char *buf, size_t max_len);
    void uartProcessCommand(const char *cmd);
#endif
