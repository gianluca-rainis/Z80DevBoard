#include "tusb.h"
#include "pico/unique_id.h"

#define _PID_MAP(itf, n) ((CFG_TUD_##itf) << (n))
#define USB_PID (0x4000 | _PID_MAP(CDC, 0) | _PID_MAP(MSC, 1))
#define USB_VID 0x2E8A // Raspberry Pi
#define USB_BCD 0x0200

// Device Descriptor
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = USB_BCD,
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = 0x0100,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,
    .bNumConfigurations = 0x01
};

uint8_t const* tud_descriptor_device_cb(void) {
    return (uint8_t const*)&desc_device;
}

// Endpoint numbers
enum {
    ITF_NUM_CDC = 0,
    ITF_NUM_CDC_DATA,
    ITF_NUM_MSC,
    ITF_NUM_TOTAL
};

#define EPNUM_CDC_NOTIF 0x81
#define EPNUM_CDC_OUT 0x02
#define EPNUM_CDC_IN 0x82
#define EPNUM_MSC_OUT 0x03
#define EPNUM_MSC_IN 0x83

#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN + TUD_MSC_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),
    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, 4, EPNUM_CDC_NOTIF, 8, EPNUM_CDC_OUT, EPNUM_CDC_IN, 64),
    TUD_MSC_DESCRIPTOR(ITF_NUM_MSC, 5, EPNUM_MSC_OUT, EPNUM_MSC_IN, 64),
};

uint8_t const* tud_descriptor_configuration_cb(uint8_t index) {
    (void)index;

    return desc_configuration;
}

// Descriptor string array
char const* string_desc_arr[] = {
    (const char[]){0x09, 0x04},     // 0: language ID (English)
    "Z80DevBoard",                  // 1: manufacturer
    "Z80DevBoard",                  // 2: product
    NULL,                           // 3: serial number (auto)
    "Z80DevBoard CDC",              // 4: CDC interface
    "Z80DevBoard MSC",              // 5: MSC interface
};

static uint16_t _desc_str[32 + 1];

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void)langid;
    uint8_t chr_count;

    switch (index) {
        case 0:
            memcpy(&_desc_str[1], string_desc_arr[0], 2);
            chr_count = 1;
            break;

        case 3:
            chr_count = 2 * PICO_UNIQUE_BOARD_ID_SIZE_BYTES;

            if (chr_count > 32)
            {
                chr_count = 32;
            }

            {
                pico_unique_board_id_t id;
                pico_get_unique_board_id(&id);

                for (size_t i = 0; i < PICO_UNIQUE_BOARD_ID_SIZE_BYTES; i++) {
                    _desc_str[1 + i * 2] = "0123456789ABCDEF"[id.id[i] >> 4];
                    _desc_str[1 + i * 2 + 1] = "0123456789ABCDEF"[id.id[i] & 0xf];
                }
            }
            break;

        default:
            if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0]))
            {
                return NULL;
            }

            const char *str = string_desc_arr[index];

            chr_count = strlen(str);

            if (chr_count > 32)
            {
                chr_count = 32;
            }

            for (size_t i = 0; i < chr_count; i++) {
                _desc_str[1 + i] = str[i];
            }
            break;
    }

    _desc_str[0] = (uint16_t)((TUSB_DESC_STRING << 8) | (2 * chr_count + 2));
    
    return _desc_str;
}
