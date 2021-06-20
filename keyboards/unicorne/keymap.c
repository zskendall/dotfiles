#include "zskendall.h"

#ifdef RGBLIGHT_ENABLE
#     include "rgb.h"
#endif

// clang-format off
/*
 * Layout macros to allow providing a predefined wrapper instead of needing to
 * provide each key individually.
 */
#define LAYOUT_unicorne_wrapper(...)     LAYOUT_unicorne(__VA_ARGS__)
#define LAYOUT_unicorne_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29  \
  ) \
  LAYOUT_unicorne_wrapper( \
    KC_TAB,   K00, K01, K02, K03, K04,        K05, K06, K07, K08, K09, KC_BSPC,  \
    CTL_ESC,  K10, K11, K12, K13, K14,        K15, K16, K17, K18, K19, CTL_QUOT, \
    KC_NO,    K20, K21, K22, K23, K24,        K25, K26, K27, K28, K29, KC_MINS,  \
                       KC_LCTL, _______THUMB_3______, KC_RGUI \
  )
#define LAYOUT_unicorne_base_wrapper(...)    LAYOUT_unicorne_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_unicorne_base_wrapper(
        ______QWERTY_L1_____, ______QWERTY_R1_____,
        ______QWERTY_L2_____, ______QWERTY_R2_____,
        ______QWERTY_L3_____, ______QWERTY_R3_____
    ),

    // Dabbling in Workman
    [_WORKMAN] = LAYOUT_unicorne_base_wrapper(
        _____WORKMAN_L1_____, _____WORKMAN_R1_____,
        _____WORKMAN_L2_____, _____WORKMAN_R2_____,
        _____WORKMAN_L3_____, _____WORKMAN_R3_____
    ),

    // Workman- and _CAIN-inspired
    [_QWORF] = LAYOUT_unicorne_base_wrapper(
        ______QWORF_L1______, ______QWORF_R1______,
        ______QWORF_L2______, ______QWORF_R2______,
        ______QWORF_L3______, ______QWORF_R3______
    ),

    // In pursuit of perfection...
    // Inspired by keyboard-design.com/letterlayout.html?layout=chia.en.matrix
    // but with less common keys on the homerow pinkies
    [_CAIN] = LAYOUT_unicorne(
	      _____, KC_Q, KC_J, KC_H , KC_F , KC_LBRC,		      KC_RBRC, KC_U , KC_L , KC_G , KC_X, _____,
	      _____, KC_C, KC_A , KC_I, KC_N , KC_W,		      KC_P, KC_T , KC_S , KC_R , KC_SCLN, _____,
	      _____, _____, KC_Y, KC_D, KC_V, _____,		        KC_K, KC_M, _____, _____, _____  , _____,
               _____, _____, _____, LT(_NUM, KC_O),            LT(_NAV, KC_ENT), RGUI_T(KC_E), _____, _____
    ),

    [_NUM] = LAYOUT_unicorne_wrapper(
        _______NUM_L1_______,             _______NUM_R1_______,
        _______NUM_L2_______,             _______NUM_R2_______, _____,
        _______NUM_L3_______,             _______NUM_R3_______,
                 _____, ______NUM_THUMB_____, _____
    ),

    [_NAV] = LAYOUT_unicorne_wrapper(
               _______NAV_L1_______,             _______NAV_R1_______, _____,
        _____, _______NAV_L2_______,             _______NAV_R2_______, LGUI(KC_L),
        TG(_ADJUST), _______NAV_L3_______,             _______NAV_R3_______,
                         _____, ______NAV_THUMB_____, _____
    ),

    [_MOUSE] = LAYOUT_unicorne_wrapper(
        _______OPS_L1_______,             _______OPS_R1_______,
        _______OPS_L2_______,             _______OPS_R2_______,
        _______OPS_L3_______,             _______OPS_R3_______,
                  _____, ______OPS_THUMB_____, _____
    ),

    [_ART] = LAYOUT_unicorne_wrapper(
        _______ART_L1_______,             _______ART_R1_______,
        _______ART_L2_______,             _______ART_R2_______,
        _______ART_L3_______,             _______ART_R3_______,
                  _____, ______ART_THUMB_____, _____
    ),
    
    // Based on default unicorne keymap
    [_ADJUST] = LAYOUT_unicorne(
        RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD , KC_NO, RGB_TOG,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, KC_NO, KC_NO  ,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_NO, KC_NO  ,                     RESET, KC_NO, KC_NO, KC_NO, KC_NO, TG(_ADJUST),
                                        _____, _____, _____, _____,         _____, _____, _____, _____
    ),
};
// clang-format on

bool defaults[] = {
  [_QWERTY] = true,
  [_WORKMAN] = true,
  [_QWORF] = true,
  [_CAIN] = true,
  [_ADJUST] = false,
};
size_t num_defaults = sizeof(defaults) / sizeof(defaults[0]);

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  keyboard_post_init_rgb_light();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = layer_state_set_rgb_light(state);
  return state;
}

// everything else based on default unicorne
// Left encoder scrolls the mousewheel, right adjusts underglow hue.
void encoder_update_user(uint8_t idx, bool cw) {
  if (idx == 0) { // idx = 0: left encoder
    if (cw) {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
#else
      tap_code(KC_PGDN);
#endif
    } else {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
#else
      tap_code(KC_PGUP);
#endif
    }
  } else { // idx = 1: right encoder
    if (cw) {
#ifdef RGB_MATRIX_ENABLE
      rgb_matrix_step();
#else
      rgblight_increase_hue_noeeprom();
#endif
    } else {
#ifdef RGB_MATRIX_ENABLE
      rgb_matrix_step_reverse();
#else
      rgblight_decrease_hue_noeeprom();
#endif
    }
  }
}
