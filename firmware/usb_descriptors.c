#include "tusb.h"

// Device Descriptor
tusb_desc_device_t const desc_device = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,
    .bDeviceClass       = TUSB_CLASS_MISC,
    .bDeviceSubClass    = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol    = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor           = 0x2E8A, // Raspberry Pi
    .idProduct          = 0x000A,
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
#define EPNUM_CDC_NOTIF 0x81
#define EPNUM_CDC_OUT 0x02
#define EPNUM_CDC_IN 0x82
#define EPNUM_MSC_OUT 0x03
#define EPNUM_MSC_IN 0x83

#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + TUD_CDC_DESC_LEN + TUD_MSC_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, 4, 0, CONFIG_TOTAL_LEN, 0x00, 100),
    TUD_CDC_DESCRIPTOR(0, 4, EPNUM_CDC_NOTIF, 8, EPNUM_CDC_OUT, EPNUM_CDC_IN, 64),
    TUD_MSC_DESCRIPTOR(2, 5, EPNUM_MSC_OUT, EPNUM_MSC_IN, 64),
};

uint8_t const* tud_descriptor_configuration_cb(uint8_t index) {
    return desc_configuration;
}

// Descriptor string array
char const* string_desc_arr[] = {
    (const char[]){0x09, 0x04},     // 0: language ID (English)
    "Z80DevBoard",                  // 1: manufacturer
    "Z80DevBoard",                  // 2: product
    "000000",                       // 3: serial number
    "Z80DevBoard CDC",              // 4: CDC interface
    "Z80DevBoard MSC",              // 5: MSC interface
};

static uint16_t _desc_str[32];

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    uint8_t chr_count;

    if (index == 0) {
        memcpy(&_desc_str[1], string_desc_arr[0], 2);
        chr_count = 1;
    }
    else {
        if (index >= sizeof(string_desc_arr) / sizeof(string_desc_arr[0])) {
            return NULL;
        }

        const char* str = string_desc_arr[index];

        chr_count = (uint8_t)strlen(str);

        if (chr_count > 31) {
            chr_count = 31;
        }

        for (uint8_t i = 0; i < chr_count; i++) {
            _desc_str[1 + i] = str[i];
        }
    }

    _desc_str[0] = (uint16_t)((TUSB_DESC_STRING << 8) | (2 * chr_count + 2));
    
    return _desc_str;
}
