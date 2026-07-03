#include "firmware.h"
#include "tusb.h"
#include "class/msc/msc_device.h"

// FAT12: 64 sectors of 512 byte (32KB)
#define DISK_BLOCK_NUM 64 // The number of sectors
#define DISK_BLOCK_SIZE 512 // The size of each sector (bytes)

static uint8_t msc_disk[DISK_BLOCK_NUM][DISK_BLOCK_SIZE]; // The disk image in memory
static bool disk_written = false;

// Boot sector FAT12
static void initDisk() {
    memset(msc_disk, 0, sizeof(msc_disk));

    // Block 0: Boot Sector
    uint8_t boot[] = {
        0xEB, 0x3C, 0x90,                               // jump + NOP
        'M','S','D','O','S','5','.','0',                // OEM
        0x00, 0x02,                                     // bytes per sector: 512
        0x01,                                           // sectors per cluster: 1
        0x01, 0x00,                                     // reserved sectors: 1
        0x01,                                           // FAT count: 1
        0x10, 0x00,                                     // root entries: 16
        0x40, 0x00,                                     // total sectors: 64
        0xF8,                                           // media type
        0x01, 0x00,                                     // sectors per FAT: 1
        0x01, 0x00,                                     // sectors per track
        0x01, 0x00,                                     // heads
        0x00, 0x00, 0x00, 0x00,                         // hidden sectors
        0x00, 0x00, 0x00, 0x00,                         // total sectors 32
        0x80,                                           // drive number
        0x00, 0x29,                                     // ext boot sig
        0x12, 0x34, 0x00, 0x00,                         // volume serial
        'Z','8','0','D','E','V','B','O','A','R','D',    // volume label (11 bytes)
        'F','A','T','1','2',' ',' ',' ',                // fs type (8 bytes)
    };

    memcpy(msc_disk[0], boot, sizeof(boot));

    msc_disk[0][510] = 0x55;
    msc_disk[0][511] = 0xAA;

    // Block 1: FAT
    msc_disk[1][0] = 0xF8;
    msc_disk[1][1] = 0xFF;
    msc_disk[1][2] = 0xFF;
}

// Initialize the MSC disk
void mscDiskInit(void) {
    initDisk();
}

// Check if the disk has been written
bool mscDiskWritten(void) {
    return disk_written;
}

// Copy the content of the disk (excluding FAT) to prog_buf
void mscDiskRead(uint8_t *prog_buf) {
    uint8_t *data_start = msc_disk[3];

    memcpy(prog_buf, data_start, FLASH_LAST_32K_SIZE);

    disk_written = false;
}

// --- Callbacks TinyUSB MSC ---
uint8_t tud_msc_get_maxlun_cb(void) {
    return 1;
}

void tud_msc_inquiry_cb(uint8_t lun, uint8_t vendor_id[8], uint8_t product_id[16], uint8_t product_rev[4]) {
    memcpy(vendor_id, "Z80DEVBD", 8);
    memcpy(product_id, "Z80DevBoard     ", 16);
    memcpy(product_rev, Z80DEVBOARD_VERSION_4BYTE, 4);
}

bool tud_msc_test_unit_ready_cb(uint8_t lun) {
    return true;
}

void tud_msc_capacity_cb(uint8_t lun, uint32_t *block_count, uint16_t *block_size) {
    *block_count = DISK_BLOCK_NUM;
    *block_size = DISK_BLOCK_SIZE;
}

bool tud_msc_start_stop_cb(uint8_t lun, uint8_t power_condition, bool start, bool load_eject) {
    return true;
}

int32_t tud_msc_read10_cb(uint8_t lun, uint32_t lba, uint32_t offset, void *buffer, uint32_t bufsize) {
    if (lba >= DISK_BLOCK_NUM) {
        return -1;
    }

    memcpy(buffer, msc_disk[lba] + offset, bufsize);

    return (int32_t)bufsize;
}

bool tud_msc_is_writable_cb(uint8_t lun) {
    return true;
}

int32_t tud_msc_write10_cb(uint8_t lun, uint32_t lba, uint32_t offset, uint8_t *buffer, uint32_t bufsize) {
    if (lba >= DISK_BLOCK_NUM) {
        return -1;
    }

    memcpy(msc_disk[lba] + offset, buffer, bufsize);

    if (lba >= 3) {
        disk_written = true;
    }

    return (int32_t)bufsize;
}

int32_t tud_msc_scsi_cb(uint8_t lun, uint8_t const scsi_cmd[16], void *buffer, uint16_t bufsize) {
    tud_msc_set_sense(lun, SCSI_SENSE_ILLEGAL_REQUEST, 0x20, 0x00);

    return -1;
}
