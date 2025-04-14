#pragma once

#include QMK_KEYBOARD_H

enum helpers { ___ = KC_TRNS, _x_ = KC_NO };

enum layers {
	BASE = 0,
	RAISE,
	LOWER,
	ADJUST,
	NUMERIC
};


// HOMEROW ALIASES
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

