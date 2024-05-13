#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify an optional status LED by GPIO number which blinks when entering the bootloader

#define MASTER_LEFT

#define FORCE_NKRO

// HOMEROW MODS
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 150
// #define PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD_PER_KEY

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md
#define UNICODE_SELECTED_MODES UC_MAC

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
