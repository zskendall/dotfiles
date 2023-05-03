#pragma once
#include "quantum.h"

void keyboard_post_init_rgb_light(void);
void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val,
                               uint8_t mode);
__attribute__((weak)) layer_state_t layer_state_set_rgb_light(
    layer_state_t state);
