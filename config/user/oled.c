#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}
#endif

#ifdef OLED_ENABLE
#include "oled_master.c"
#include "oled_slave.c"
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_master_state();
  } else {
    oled_render_slave_animation();
  }

  return false;
}
#endif
