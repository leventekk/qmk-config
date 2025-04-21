enum macros {
    NEXT_DESKTOP = SAFE_RANGE,
    PREV_DESKTOP,
    SCREENSHOT,
};

// Time threshold for macros (in ms)
#define MACRO_DELAY_THRESHOLD 150

// Variables to track macro press times
static uint16_t macro_timer      = 0;
static bool     macro_triggered  = false;
static bool     slash_key_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Add special handling for slash key to prevent accidental triggering
    if (keycode == KC_SLSH) {
        if (record->event.pressed) {
            slash_key_active = true;
            // Start timer when slash is pressed
            macro_timer = timer_read();
        } else {
            // When slash is released
            slash_key_active = false;
            // If released very quickly, we might want to prevent other actions
            if (timer_elapsed(macro_timer) < MACRO_DELAY_THRESHOLD) {
                // This is a quick tap, intended to type a slash
                macro_triggered = true;
            } else {
                macro_triggered = false;
            }
        }
        return true; // Let QMK process the slash key normally
    }

    // For actual macro keys
    if (keycode == PREV_DESKTOP || keycode == NEXT_DESKTOP || keycode == SCREENSHOT) {
        if (record->event.pressed) {
            // Check if we're typing too fast - possible accidental trigger
            if (slash_key_active || (timer_elapsed(macro_timer) < MACRO_DELAY_THRESHOLD && macro_triggered)) {
                // This is likely an accidental press while typing quickly
                return false; // Ignore this keystroke
            }

            switch (keycode) {
                case PREV_DESKTOP:
                    register_code(KC_LCTL);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LCTL);
                    break;

                case NEXT_DESKTOP:
                    register_code(KC_LCTL);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LCTL);
                    break;

                case SCREENSHOT:
                    register_code(KC_LGUI);
                    register_code(KC_LSFT);
                    tap_code(KC_4);
                    unregister_code(KC_LGUI);
                    unregister_code(KC_LSFT);
                    break;
            }

            macro_timer     = timer_read();
            macro_triggered = true;
            return false;
        }
    }

    // Reset macro trigger state after a certain period
    if (timer_elapsed(macro_timer) > 500) {
        macro_triggered = false;
    }

    return true;
};
