#ifdef RGBLIGHT_ENABLE

#include "rgb.h"

#include "zskendall.h"

void keyboard_post_init_rgb_light(void) {
  rgblight_sethsv(RGBLIGHT_DEFAULT_HSV);
  layer_state_set_rgb_light(layer_state);
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val,
                               uint8_t mode) {
  rgblight_sethsv_noeeprom(hue, sat, val);
  rgblight_mode_noeeprom(mode);
}

#endif
