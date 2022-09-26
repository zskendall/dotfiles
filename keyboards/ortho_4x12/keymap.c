#include "zskendall.h"

enum custom_keycodes {
  NUM = KEYMAP_SAFE_RANGE,
  NAV,
  ADJUST
};

#define META_SPC RGUI_T(KC_SPC)
#define NAV_RET LT(_NAV, KC_ENT)
#define NUM MO(_NUM)

// clang-format off
/*
 * Layout macros to allow providing a predefined wrapper instead of needing to
 * provide each key individually.
 */
#define LAYOUT_ortho_4x12_wrapper(...)     LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_4x12_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K40  \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
    KC_TAB,   K00, K01, K02, K03, K04,          K05, K06, K07, K08, K09, KC_BSPC,  \
    CTL_ESC,  K10, K11, K12, K13, K14,          K15, K16, K17, K18, K19, CTL_QUOT, \
    KC_LALT,    K20, K21, K22, K23, K24,        K25, K26, K27, K28, K29, RALT_T(KC_MINS),  \
    K30,      K31, K32, K33, K34, K35,          K35, K36, K37, K38, K39, K40 \
  )
#define LAYOUT_ortho_4x12_base_wrapper(...)    LAYOUT_ortho_4x12_base(__VA_ARGS__)

#define ______DEFAULT_4_____    KC_NO, KC_LCTL, KC_LALT, KC_LSFT, NUM, META_SPC, NAV_RET, LSFT_T(KC_LEFT), RALT_T(KC_DOWN), RCTL_T(KC_UP), KC_RIGHT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /** Base Layer (QWERTY) */
    [_QWERTY] = LAYOUT_ortho_4x12_base_wrapper(
        ______QWERTY_L1_____, ______QWERTY_R1_____,
        ______QWERTY_L2_____, ______QWERTY_R2_____,
        ______QWERTY_L3_____, ______QWERTY_R3_____,
                    ______DEFAULT_4_____
    ),

    /** Numeric Layer */
    [_NUM] = LAYOUT_ortho_4x12_wrapper(
        _____, _______NUM_L1_______,             _______NUM_R1_______,
               _______NUM_L2_______,             _______NUM_R2_______, META_RET,
               _______NUM_L3_______,             _______NUM_R3_______,
        _____, _____, _____, _____, _____, _____, KC_0, _____, _____, _____, _____, _____
    ),

    /** Directional Navigation Layer */
    [_NAV] = LAYOUT_ortho_4x12_wrapper(
               _______NAV_L1_______,             RGUI(KC_6), KC_LPRN, KC_RPRN, RGUI(KC_7), RGUI(KC_8), _____,
        _____, _______NAV_L2_______,             _______NAV_R2_______, LGUI(KC_L),
        _____, _______NAV_L3_______,             LCTL(KC_6), KC_LBRC, KC_RBRC, LCTL(KC_7), LCTL(KC_9), MS_TOG,
        _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
    ),

    /** Mouse/Media Layer */
    [_MOUSE] = LAYOUT_ortho_4x12_wrapper(
        _______OPS_L1_______,             _______OPS_R1_______,
        _______OPS_L2_______,             _______OPS_R2_______,
        _______OPS_L3_______,             _______OPS_R3_______,
        _____, _____, _____, _____, KC_BTN1, KC_BTN2, KC_BTN2, KC_BTN3, _____, _____, _____, _____
    ),

    /**
     * Condensed Art Layer
     * If tap dance is enabled, the keys from the right are moved into a
     *     double dance on the left.
     * Otherwise the left has common Krita functions.
     * Only fall-through mod functions on right half.
     */
    [_ART] = LAYOUT_ortho_4x12_wrapper(
        _______ART_L1_______,             _______ART_R1_______,
        _______ART_L2_______,             _______ART_R2_______,
        _______ART_L3_______,             _______ART_R3_______,
        _____, _____, _____, LSFT_T(KC_INS), _____, _____, _____, _____, _____, _____, _____, _____
    ),
    
    // Based on default Planck keymap:
    // https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/default/keymap.c
    [_ADJUST] = LAYOUT_planck_grid(
        _____, QK_BOOT,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL,
        _____, _____, _____,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _____,  _____,  _____,  _____,  _____,
        _____, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____, _____, _____, _____,  _____, _____, _____
    ),
};
// clang-format on

bool defaults[] = {
  [_QWERTY] = true,
  [_ADJUST] = false,
};
size_t num_defaults = sizeof(defaults) / sizeof(defaults[0]);

// Handle tri-layer for num/nav/adjust
// Based on buswerks' keymap:
// https://github.com/qmk/qmk_firmware/blob/master/layouts/community/ortho_4x12/buswerks/keymap.c
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUM:
      if (record->event.pressed) {
        layer_on(_NUM);
        update_tri_layer(_NUM, _NAV, _ADJUST);
      } else {
        layer_off(_NUM);
        update_tri_layer(_NUM, _NAV, _ADJUST);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_NUM, _NAV, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_NUM, _NAV, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
