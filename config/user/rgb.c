/* void keyboard_post_init_user(void) { */
/*   // Initialize RGB to static black */
/*   rgblight_enable_noeeprom(); */
/*   rgblight_sethsv_noeeprom(HSV_BLACK); */
/*   rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
/* } */

// disable status led on Liatris micro controller
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

static uint32_t key_timer; // timer for last keyboard activity, use 32bit value
                           // and function to make longer idle time possible
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke
                               // whenever any activity happens
static void
check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean

void refresh_rgb(void) {
  key_timer = timer_read32(); // store time of last refresh
  if (is_rgb_timeout) {
    is_rgb_timeout = false;
    rgblight_wakeup();
  }
}
void check_rgb_timeout(void) {
  if (!is_rgb_timeout &&
      timer_elapsed32(key_timer) >
          RGBLIGHT_TIMEOUT) // check if RGB has already timeout and if enough
                            // time has passed
  {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
}

void set_default_rgb_color(void) {
  if (!is_rgb_timeout) {
    rgblight_setrgb_at(RGB_PURPLE, 0);
    rgblight_setrgb_at(RGB_PURPLE, 1);
  }
}
/* Then, call the above functions from QMK's built in post processing functions
 * like so */
/* Runs at the end of each scan loop, check if RGB timeout has occured or not */
void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  set_default_rgb_color();
#endif
}
/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed)
    refresh_rgb();
#endif
}
/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_TIMEOUT
  refresh_rgb();
#endif
}
