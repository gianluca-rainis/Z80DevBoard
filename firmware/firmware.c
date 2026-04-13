#include "pico/stdlib.h"
#include "firmware.h"

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
    gpio_set_dir(GPIO_Z80_RESET, GPIO_OUT);
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
    
    if (gpio_get(GPIO_Z80_PROGRAM_LOAD) == 1) {
        // Save the new program of the Z80 to flash
    }
}

/* 
    This function is runned in a loop after the setup function.
*/
void loop() {

}