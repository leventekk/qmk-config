#include <stdint.h>
#define COMBO_COUNT (sizeof(key_combos) / sizeof(combo_t))

enum combos {
  COMBO_WE_ESC,
  COMBO_EW_ESC,
  COMBO_UI_BACKSPACE,
  COMBO_IU_BACKSPACE,
  COMBO_IO_DEL,
  COMBO_OI_DEL,
  COMBO_GH_CAPS_LOCK,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Navigation combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM ew_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM iu_combo[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM oi_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    // Navigation combos
    [COMBO_WE_ESC] = COMBO(we_combo, KC_ESC),
    [COMBO_EW_ESC] = COMBO(ew_combo, KC_ESC),
    [COMBO_UI_BACKSPACE] = COMBO(ui_combo, KC_BSPC),
    [COMBO_IU_BACKSPACE] = COMBO(iu_combo, KC_BSPC),
    [COMBO_IO_DEL] = COMBO(io_combo, KC_DEL),
    [COMBO_OI_DEL] = COMBO(oi_combo, KC_DEL),
    [COMBO_GH_CAPS_LOCK] = COMBO(gh_combo, QK_CAPS_WORD_TOGGLE),
};
