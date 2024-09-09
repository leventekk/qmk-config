#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5

#define MASTER_LEFT

#define FORCE_NKRO

#define TAPPING_TERM 200
#define QUICK_TAP_TERM 150

#define UNICODE_SELECTED_MODES UC_MAC

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#if DEVICE == liatris
#undef WS2812_DI_PIN
#define WS2812_DI_PIN 25

#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}

#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0

#define RGBLIGHT_SLEEP  // enable rgblight_suspend() and rgblight_wakeup() in keymap.c
#define RGBLIGHT_TIMEOUT 20000  // ms to wait until rgblight time out, 20K ms is 20sec.
#endif
