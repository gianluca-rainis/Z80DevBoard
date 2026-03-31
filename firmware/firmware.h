#ifndef FIRMWARE
    #define FIRMWARE

    #define GPIO_RP2040_FIRMWARE_LOAD 0
    #define GPIO_Z80_PROGRAM_LOAD 1
    #define GPIO_RAM_ADDRESS 2
    #define GPIO_RAM_DATA 3
    #define GPIO_SHIFT_CLOCK 4
    #define GPIO_RAM_OPERATION 5
    #define GPIO_Z80_RESET 6
    #define GPIO_RAM_DATA_READ 7
    #define GPIO_RAM_DATA_SHIFT 8
    #define GPIO_Z80_BUSREQ 10
    #define GPIO_Z80_BUSACK 11

    # define GPIO_EXPANSION_1 12
    # define GPIO_EXPANSION_2 13
    # define GPIO_EXPANSION_3 14
    # define GPIO_EXPANSION_4 15
    # define GPIO_EXPANSION_5 16
    # define GPIO_EXPANSION_6 17
    # define GPIO_EXPANSION_7 18
    # define GPIO_EXPANSION_8 19
    # define GPIO_EXPANSION_9 20
    # define GPIO_EXPANSION_10 21
    # define GPIO_EXPANSION_11 22
    # define GPIO_EXPANSION_12 23
    # define GPIO_EXPANSION_13 24
    # define GPIO_EXPANSION_14 25
    # define GPIO_EXPANSION_ADC0 26
    # define GPIO_EXPANSION_ADC1 27
    # define GPIO_EXPANSION_ADC2 28
    # define GPIO_EXPANSION_ADC3 29

    // Functions
    void setup();
    void loop();
#endif