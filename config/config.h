// https://www.jonashietala.se/blog/2022/09/06/the_current_t-34_keyboard_layout/
#pragma once

// rp2040 setings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5

#define MASTER_LEFT

#define FORCE_NKRO

// Home-row mods: https://precondition.github.io/home-row-mods#tap-hold-configuration-settings
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM_PER_KEY
#ifdef TAPPING_TERM_PER_KEY
#    define TAPPING_TERM 170
#else
// Only for thumbs
#    define TAPPING_TERM 200
#endif
#define QUICK_TAP_TERM 150

// Combos
#undef COMBO_TERM
#define COMBO_TERM 35
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space
#define COMBO_ONLY_FROM_LAYER 0

#define UNICODE_SELECTED_MODES UC_MAC

// OLED support
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
