#include "pico/stdlib.h"
#include "firmware.h"

/* 
    This function is runned only once at the start of the program.
*/
void setup() {
    // Initialize the GPIO pins
    gpio_init(0);
    gpio_set_dir(0, GPIO_IN);
    gpio_init(1);
    gpio_set_dir(1, GPIO_IN);
    gpio_init(2);
    gpio_set_dir(2, GPIO_OUT);
    gpio_init(3);
    gpio_set_dir(3, GPIO_OUT);
    gpio_init(4);
    gpio_set_dir(4, GPIO_OUT);
    gpio_init(5);
    gpio_set_dir(5, GPIO_OUT);
    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);
    gpio_init(7);
    gpio_set_dir(7, GPIO_IN);
    gpio_init(8);
    gpio_set_dir(8, GPIO_OUT);
    gpio_init(10);
    gpio_set_dir(10, GPIO_OUT);
    gpio_init(11);
    gpio_set_dir(11, GPIO_IN);

    // Expansion pins - decomment for use. Must be commented if not used.
    /* gpio_init(12);
    gpio_set_dir(12, GPIO_OUT);
    gpio_init(13);
    gpio_set_dir(13, GPIO_OUT);
    gpio_init(14);
    gpio_set_dir(14, GPIO_OUT);
    gpio_init(15);
    gpio_set_dir(15, GPIO_OUT);
    gpio_init(16);
    gpio_set_dir(16, GPIO_OUT);
    gpio_init(17);
    gpio_set_dir(17, GPIO_OUT);
    gpio_init(18);
    gpio_set_dir(18, GPIO_OUT);
    gpio_init(19);
    gpio_set_dir(19, GPIO_OUT);
    gpio_init(20);
    gpio_set_dir(20, GPIO_OUT);
    gpio_init(21);
    gpio_set_dir(21, GPIO_OUT);
    gpio_init(22);
    gpio_set_dir(22, GPIO_OUT);
    gpio_init(23);
    gpio_set_dir(23, GPIO_OUT);
    gpio_init(24);
    gpio_set_dir(24, GPIO_OUT);
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT); */
}

/* 
    This function is runned in a loop after the setup function.
*/
void loop() {

}