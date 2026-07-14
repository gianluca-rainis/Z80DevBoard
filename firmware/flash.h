#include <stdint.h>
#include <string.h>

#ifndef Z80DEVBOARD_FLASH
    #define Z80DEVBOARD_FLASH

    #define FLASH_XIP_BASE 0x10000000u          // The mapped memory address of the flash

    #define FLASH_LAST_32K_OFFSET 0x3F8000u     // Offset or the last 32k of the flash
    #define FLASH_LAST_32K_SIZE 0x8000u         // 32k in hex
    #define FLASH_LAST_32K_ADDR (FLASH_XIP_BASE + FLASH_LAST_32K_OFFSET)    // The address of the last 32k

    void flashRead(uint32_t offset, uint8_t *destination, size_t length);
    void loadZ80ProgramFromFlash(uint8_t *ram_buf);
    void saveZ80ProgramInFlash(const uint8_t *prog_buf);
#endif
