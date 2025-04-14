enum macros {
    NEXT_DESKTOP = SAFE_RANGE,
    PREV_DESKTOP,
    SCREENSHOT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PREV_DESKTOP:
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
                unregister_code(KC_LCTL);

                return false;

            case NEXT_DESKTOP:
                register_code(KC_LCTL);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCTL);

                return false;

            case SCREENSHOT:
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_4);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);

                return false;
        }
    }

    return true;
};
