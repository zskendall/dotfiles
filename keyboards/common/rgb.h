#pragma once
#include "quantum.h"

void keyboard_post_init_rgb_light(void);
__attribute__((weak)) layer_state_t layer_state_set_rgb_light(
    layer_state_t state);

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode);

#ifdef RGBLIGHT_LAYERS
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#lighting-layers
extern const rgblight_segment_t* const PROGMEM rgb_layers[];
extern const rgblight_segment_t PROGMEM no_indicator[];

__attribute__((weak)) void rgblight_set_layer_state_keymap(layer_state_t state);
#endif
