#ifndef FIRMWARE
    #define FIRMWARE

    #define GPIO_RP2040_FIRMWARE_LOAD 0
    #define GPIO_Z80_PROGRAM_LOAD 1
    #define GPIO_RAM_ADDRESS 2
    #define GPIO_RAM_DATA 3
    #define GPIO_SHIFT_CLOCK 4
    #define GPIO_RAM_OPERATION 5
    #define GPIO_GND 6
    #define GPIO_RAM_DATA_READ 7

    // Functions
    void setup();
    void loop();
#endif