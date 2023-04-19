#pragma once
#include "quantum.h"

void keyboard_post_init_rgb_light(void);
__attribute__((weak)) layer_state_t layer_state_set_rgb_light(
    layer_state_t state);
