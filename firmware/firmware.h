#include "flash.h"
#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"

#ifndef Z80DEVBOARD_FIRMWARE
    #define Z80DEVBOARD_FIRMWARE

    #define Z80DEVBOARD_VERSION "1.8.0"
    #define Z80DEVBOARD_VERSION_4BYTE "1.8 "
    #define Z80DEVBOARD_FIRMWARE_VERSION "1.0.0"

    #define GPIO_Z80_PROGRAM_LOAD 0
    #define GPIO_RAM_ADDRESS 1
    #define GPIO_RAM_DATA 2
    #define GPIO_SHIFT_CLOCK 3
    #define GPIO_RAM_OPERATION 4
    #define GPIO_Z80_RESET 5
    #define GPIO_RAM_DATA_READ 6
    #define GPIO_RAM_DATA_SHIFT 7
    #define GPIO_Z80_BUSREQ 10
    #define GPIO_Z80_BUSACK 11

    #define GPIO_EXPANSION_1 12
    #define GPIO_EXPANSION_2 13
    #define GPIO_EXPANSION_3 14
    #define GPIO_EXPANSION_4 15
    #define GPIO_EXPANSION_5 16
    #define GPIO_EXPANSION_6 17
    #define GPIO_EXPANSION_7 18
    #define GPIO_EXPANSION_8 19
    #define GPIO_EXPANSION_9 20
    #define GPIO_EXPANSION_10 21
    #define GPIO_EXPANSION_11 22
    #define GPIO_EXPANSION_12 23
    #define GPIO_EXPANSION_13 24
    #define GPIO_EXPANSION_14 25
    #define GPIO_EXPANSION_ADC0 26
    #define GPIO_EXPANSION_ADC1 27
    #define GPIO_EXPANSION_ADC2 28
    #define GPIO_EXPANSION_ADC3 29

    // Variables
    extern bool wasSerialConnected; // Flag to check if the serial was connected at least once
    extern bool showLogs; // Flag to check if the logs are enabled by the user

    // Main functions
    void setup();
    void loop();

    // Bus functions
    bool sendBusReqAndWaitBusAck();
    bool releaseBusReq();

    // Ram operations
    bool accessRamAddress(uint16_t address);
    uint8_t readRamCell();
    bool writeRamCell(uint8_t data);

    // Z80 operations
    void resetZ80();
    void loadZ80ProgramInRam();

    // Support functions
    void printSerialBanner();
#endif

#ifndef null
    #define null 0
#endif
