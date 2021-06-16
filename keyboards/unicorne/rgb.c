#ifdef RGBLIGHT_ENABLE

#    include "zskendall.h"
#    include "rgb.h"

void keyboard_post_init_rgb_light(void) {
  rgblight_sethsv_blue();
  layer_state_set_rgb_light(layer_state);
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
  rgblight_sethsv_noeeprom(hue, sat, val);
  rgblight_mode_noeeprom(mode);
}

layer_state_t layer_state_set_rgb_light(layer_state_t state) {
#     ifdef RGBLIGHT_ENABLE
  switch(get_highest_layer(state | default_layer_state)) {
    case _ART:
      rgblight_set_hsv_and_mode(HSV_RED, RGBLIGHT_MODE_SNAKE);
      break;
    case _MOUSE:
      rgblight_set_hsv_and_mode(HSV_CYAN, RGBLIGHT_MODE_ALTERNATING);
      break;
    case _ADJUST:
      rgblight_set_hsv_and_mode(HSV_BLUE, RGBLIGHT_MODE_RAINBOW_MOOD + 2);
      break;
    case _WORKMAN:
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case _CHIA:
      rgblight_sethsv_noeeprom(HSV_MAGENTA);
      break;
    case _CAIN:
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      break;
    case _QWERTY:
      rgblight_sethsv(HSV_BLUE);
      // fall-through
    default:
      if (rgblight_get_mode() != RGBLIGHT_DEFAULT_MODE) {
        // reset defaults if coming from another layer
        rgblight_set_hsv_and_mode(HSV_BLUE, RGBLIGHT_DEFAULT_MODE);
      }
  }
#     endif
  return state;
}

#endif
