#include QMK_KEYBOARD_H

enum helpers { ___ = KC_TRNS, _x_ = KC_NO };

enum layers { BASE, RAISE, LOWER, ADJUST, NUMERIC };

// HOMEROW ALIASES
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// CUSTOM KEYBINDS
#include "./user/combos.c"
#include "./user/macros.c"
#include "./user/oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        // ╭──────────┬───────────┬──────────┬──────────┬──────────┬──────────╮
        // │  TAB     │  Q       │  W       │  E       │  R        │  T       │
        // │  Y       │  U        │  I       │  O       │  P       │BACKSPACE │
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_BSPC,
        // ├──────────┼───────────┼──────────┼──────────┼──────────┼──────────┤
        // │  CTRL    │  A       │  S       │  D       │  F        │  G       │
        // │  H       │  J        │  K       │  L       │  ;       │  "       │
        KC_LCTL, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K,
        HOME_L, HOME_SCLN, KC_ESC,
        // ├──────────┼───────────┼──────────┼──────────┼──────────┼──────────┤
        // │  SHIFT   │  Z       │  X       │  C       │  V        │  B       │
        // │  N       │  M        │  ,       │  .       │  /       │  SHIFT   │
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
        KC_SLSH, KC_RSFT,
        // ┤──────────┼───────────┼──────────┼──────────┴──────────┴──────────╯
        KC_LGUI, MO(RAISE), KC_SPC, KC_ENT, MO(LOWER), KC_RALT),
    [RAISE] = LAYOUT_split_3x6_3(
        // ╭──────────┬──────────┬────────────┬──────────┬──────────┬──────────╮
        // │          │  1       │  2       │  3       │  4       │  5       │
        // │  6       │  7       │  8         │  9       │  0       │          │
        ___, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, ___,
        // ├──────────┼──────────┼────────────┼──────────┼──────────┼──────────┤
        // │          │  DEL     │ CAPS     │          │          │          │
        // │  LEFT    │  DOWN    │  UP        │  RIGHT   │          │          │
        ___, KC_DEL, KC_CAPS, _x_, _x_, _x_, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
        ___, ___,
        // ├──────────┼──────────┼────────────┼──────────┼──────────┼──────────┤
        // │          │          │          │          │          │          │
        // │  HOME    │  PG DOWN │  PG UP     │  END     │          │          │
        ___, _x_, _x_, _x_, _x_, _x_, KC_HOME, KC_PGUP, KC_PGDN, KC_END, _x_,
        ___,
        // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤
        ___, _x_, ___, ___, MO(ADJUST), ___),

    [LOWER] = LAYOUT_split_3x6_3(
        // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
        // │          │  !       │  @       │  #       │  $       │  %       │
        // │  ^       │  &       │  *       │  `       │  ~       │          │
        ___, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,
        KC_ASTR, KC_GRAVE, KC_TILD, ___,
        // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        // │          │  "       │  [       │  {       │  (       │          │
        // │  /       │  -       │  =       │  :       │  ;       │          │
        ___, KC_DQT, KC_LBRC, KC_LCBR, KC_LPRN, _x_, KC_SLSH, KC_MINUS, KC_EQL,
        KC_COLON, KC_SCLN, _x_,
        // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        // │          │  '       │  ]       │  }       │  )       │          │
        // │  \       │  _       │  +       │  |       │  ?       │          │
        ___, KC_QUOT, KC_RBRC, KC_RCBR, KC_RPRN, _x_, KC_BSLS, KC_UNDS, KC_PLUS,
        KC_PIPE, KC_QUES, _x_,
        // ╰──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤
        ___, MO(ADJUST), ___, ___, _x_, ___),

    [ADJUST] = LAYOUT_split_3x6_3(
        // ╭─────────────┬──────────┬──────────┬─────────────┬─────────────┬──────────╮
        // │          │          │ PREVSONG    │ NEXTSONG    │          │
        QK_BOOT, _x_, _x_, _x_, _x_, _x_, _x_, _x_, _x_, KC_MPRV, KC_MNXT, _x_,
        // ├─────────────┼──────────┼──────────┼─────────────┼─────────────┼──────────┤
        // │          │          │          │          │ PREV DESKTOP  │ NEXT
        // DESKTOP │    │             │          │          │ VOL DOWN    │  VOL
        // UP     │          │
        _x_, QK_UNDERGLOW_TOGGLE, QK_UNDERGLOW_MODE_PREVIOUS,
        QK_UNDERGLOW_MODE_NEXT, TG(NUMERIC), PREV_DESKTOP, NEXT_DESKTOP, _x_,
        _x_, KC_VOLD, KC_VOLU, _x_,
        // ├─────────────┼──────────┼──────────┼─────────────┼─────────────┼──────────┤
        // SCREENSHOT   │    │             │          │          │ MUTE        │
        // PLAY_PAUSE  │          │
        _x_, QK_UNDERGLOW_HUE_DOWN, QK_UNDERGLOW_HUE_UP, _x_, _x_, SCREENSHOT,
        _x_, _x_, _x_, KC_MUTE, KC_MPLY, _x_,
        // ╰──────────┴──────────┴──────────┼──────────┼───────────────┼──────────────┤
        ___, ___, ___, ___, ___, ___),
    [NUMERIC] = LAYOUT_split_3x6_3(
        // ╭──────────┬───────────┬──────────┬──────────┬──────────┬──────────╮
        // │  TAB     │  Q       │  W       │  E       │  R        │  T       │
        // │  Y       │  U        │  I       │  O       │  P       │BACKSPACE │
        ___, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, ___,
        // ├──────────┼───────────┼──────────┼──────────┼──────────┼──────────┤
        // │  CTRL    │  A       │  S       │  D       │  F        │  G       │
        // │  H       │  J        │  K       │  L       │  ;       │  "       │
        _x_, _x_, _x_, _x_, TG(NUMERIC), _x_, _x_, _x_, _x_, _x_, ___, _x_,
        // ├──────────┼───────────┼──────────┼──────────┼──────────┼──────────┤
        // │  SHIFT   │  Z       │  X       │  C       │  V        │  B       │
        // │  N       │  M        │  ,       │  .       │  /       │  SHIFT   │
        _x_, _x_, _x_, _x_, _x_, _x_, _x_, _x_, ___, ___, ___, _x_,
        // ┤──────────┼───────────┼──────────┼──────────┴──────────┴──────────╯
        ___, ___, ___, ___, ___, ___),
};
