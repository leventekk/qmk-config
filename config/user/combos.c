enum combos { COMBO_JK_ESC, COMBO_KJ_ESC, COMBO_GH_CAPS_LOCK, COMBO_LENGTH };

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_combo[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM kj_combo[] = {HOME_K, HOME_J, COMBO_END};
const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    [COMBO_JK_ESC] = COMBO(jk_combo, KC_ESC),
    [COMBO_KJ_ESC] = COMBO(kj_combo, KC_ESC),
    [COMBO_GH_CAPS_LOCK] = COMBO(gh_combo, QK_CAPS_WORD_TOGGLE),
};
