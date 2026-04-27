#include <stdint.h>
#include <string.h>

#ifndef FLASH
    #define FLASH

    #define FLASH_XIP_BASE 0x10000000u

    #define FLASH_LAST_32K_OFFSET 0x3F8000u
    #define FLASH_LAST_32K_SIZE 0x8000u
    #define FLASH_LAST_32K_ADDR (FLASH_XIP_BASE + FLASH_LAST_32K_OFFSET)

    void flash_read(uint32_t offset, uint8_t *destination, size_t length);
    void load_z80_program_from_flash(uint8_t *ram_buf);
#endif