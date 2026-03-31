/* 
    RP2040 connections:
    GPIO0 - Input 0 save RP2040 new firmware from USB to flash
    GPIO1 - Input 0 save Z80 new program from USB to flash
    GPIO2 - Output of the address of the RAM (serial 16 bit)
    GPIO3 - Output of the data of the RAM (serial 8 bit)
    GPIO4 - Output of the rotation clock of the shift registers
    GPIO5 - Output of the direction of the operation to RAM (1 for write, 0 for read)
    GPIO6 - Output of the RESET signal to Z80
    GPIO7 - Input of the byte of data read from RAM (serial 8 bit)
    GPIO8 - Output of the moment when read the RAM (0 for read, 1 for shift)
    GPIO9 - DISCONNECTED
    GPIO10 - Output of the BUSREQ signal to Z80
    GPIO11 - Input of the BUSACK signal from Z80
    GPIO12 - Expansion Pin
    GPIO13 - Expansion Pin
    GPIO14 - Expansion Pin
    GPIO15 - Expansion Pin
    GPIO16 - Expansion Pin
    GPIO17 - Expansion Pin
    GPIO18 - Expansion Pin
    GPIO19 - Expansion Pin
    GPIO20 - Expansion Pin
    GPIO21 - Expansion Pin
    GPIO22 - Expansion Pin
    GPIO23 - Expansion Pin
    GPIO24 - Expansion Pin
    GPIO25 - Expansion Pin
    GPIO26-ADC0 - Expansion Pin
    GPIO27-ADC1 - Expansion Pin
    GPIO28-ADC2 - Expansion Pin
    GPIO29-ADC3 - Expansion Pin
*/

#include "firmware.h"
#include <stdbool.h>

int main() {
    setup();

    while (true)
    {
        loop();
    }
}