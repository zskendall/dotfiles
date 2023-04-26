#include "zskendall.h"

#ifdef RGBLIGHT_ENABLE
#include "rgb.h"
#endif

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap. Use _keymap instead of _user
// functions in the keymaps
// https://docs.qmk.fm/#/feature_userspace?id=customized-functions
__attribute__((weak)) bool process_record_keymap(uint16_t keycode,
                                                 keyrecord_t *record) {
  return true;
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  keyboard_post_init_rgb_light();
#endif
#ifdef RGBLIGHT_LAYERS
  rgblight_layers = rgb_layers;
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
  rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
  // rgblight_set_layer_state(_MOUSE, layer_state_cmp(state, _MOUSE));
  // rgblight_set_layer_state(_ART, layer_state_cmp(state, _ART));
  // rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
  rgblight_set_layer_state_keymap(state);
#elif RGBLIGHT_ENABLE
  state = layer_state_set_rgb_light(state);
#endif
  return state;
}

// Defines actions for global custom keycodes defined in common header.
// Then runs the _keymap's recod handier if not processed here,
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CHDF:
      if (record->event.pressed) {
        uint32_t default_layer = biton32(default_layer_state);
        for (uint8_t i = 1; i < num_defaults; i++) {
          if (defaults[(default_layer + i) % num_defaults]) {
            default_layer_set(1U << (default_layer + i) % num_defaults);
            return false;
          }
        }
      }
      return false;
  }
  return process_record_keymap(keycode, record);
}
