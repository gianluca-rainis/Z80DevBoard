#include "flash.h"

/* 
 * QSPI Flash access via XIP (eXecute In Place)
 * W25Q32JVSS connected to Pico QSPI:
 * - Total: 4 MB (0x000000 - 0x3FFFFF)
 * - Last 32 KB reserved for Z80 program: 0x3F8000 - 0x3FFFFF
 * - Mapped in memory at: 0x10000000 + offset
 */

// Read from QSPI flash via direct XIP mapping
void flashRead(uint32_t offset, uint8_t *destination, size_t length) {
    const uint8_t *flash_ptr = (uint8_t *)(FLASH_XIP_BASE + offset);

    memcpy(destination, flash_ptr, length);
}

// Load Z80 program from the last 32 KB of flash
void loadZ80ProgramFromFlash(uint8_t *ram_buf) {
    const uint8_t *program_ptr = (uint8_t *)FLASH_LAST_32K_ADDR;

    memcpy(ram_buf, program_ptr, FLASH_LAST_32K_SIZE);
}
