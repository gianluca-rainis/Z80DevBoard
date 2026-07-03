#include <stdbool.h>
#include <stdint.h>

#ifndef Z80DEVBOARD_MSC_DISK_H
    #define Z80DEVBOARD_MSC_DISK_H

    void mscDiskInit(void);
    bool mscDiskWritten(void);
    void mscDiskRead(uint8_t *prog_buf);
#endif
