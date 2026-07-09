#ifndef _TUSB_CONFIG_H_
    #define _TUSB_CONFIG_H_

    #define BOARD_TUD_RHPORT 0
    #define BOARD_TUD_MAX_SPEED OPT_MODE_DEFAULT_SPEED

    #define CFG_TUSB_MCU OPT_MCU_RP2040
    #define CFG_TUSB_OS OPT_OS_PICO
    #define CFG_TUSB_DEBUG 0

    #define CFG_TUD_ENABLED 1
    #define CFG_TUD_MAX_SPEED BOARD_TUD_MAX_SPEED

    #ifndef CFG_TUSB_MEM_SECTION
        #define CFG_TUSB_MEM_SECTION
    #endif

    #ifndef CFG_TUSB_MEM_ALIGN
        #define CFG_TUSB_MEM_ALIGN __attribute__ ((aligned(4)))
    #endif

    #define CFG_TUD_ENDPOINT0_SIZE 64

    #define CFG_TUD_CDC 1
    #define CFG_TUD_MSC 1
    #define CFG_TUD_HID 0
    #define CFG_TUD_MIDI 0
    #define CFG_TUD_VENDOR 0

    #define CFG_TUD_CDC_RX_BUFSIZE 64
    #define CFG_TUD_CDC_TX_BUFSIZE 64
    #define CFG_TUD_CDC_EP_BUFSIZE 64
    #define CFG_TUD_MSC_EP_BUFSIZE 512
#endif
