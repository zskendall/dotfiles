#include "zskendall.h"

#include QMK_KEYBOARD_H

enum kb_layers { MAC_BASE, WIN_BASE };

enum custom_keycodes { APP };

#define KC_FLXP LGUI(KC_E)
#define ADJ MO(_ADJUST)
#define NAV_SPC LT(_NAV, KC_SPC)
#define HR_S LT(_NUM, KC_S)
#define HR_F LALT_T(KC_F)
#define HR_J RALT_T(KC_J)
#define HR_D LGUI_T(KC_D)
#define HR_K RGUI_T(KC_K)

#define LAYOUT_ansi_61_wrapper(...) LAYOUT_ansi_61(__VA_ARGS__)

#define ___DEFAULT_NUM_60___                                                   \
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, \
      KC_EQL, KC_BSPC

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_61_wrapper(
        ___DEFAULT_NUM_60___,
        KC_TAB,  ______QWERTY_L1_____, ______QWERTY_R1_____,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        CTL_ESC, KC_A, HR_S, HR_D, HR_F, KC_G, KC_H, HR_J, HR_K, KC_L, KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT, ______QWERTY_L3_____, ______QWERTY_R3_____,            KC_RSFT,
        KC_LCTL, KC_LOPT,  KC_LCMD,                    NAV_SPC,                             KC_ROPT,  KC_RCMD, KC_RCTL, ADJ),


    [WIN_BASE] = LAYOUT_ansi_61_wrapper(
        ___DEFAULT_NUM_60___,
        KC_TAB,  ______QWERTY_L1_____, ______QWERTY_R1_____,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        CTL_ESC, KC_A, HR_S, HR_D, HR_F, KC_G, KC_H, HR_J, HR_K, KC_L, KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT, ______QWERTY_L3_____, ______QWERTY_R3_____,            KC_RSFT,
        KC_LCTL, KC_LWIN,  KC_LALT,                    NAV_SPC,                             KC_RGUI,  _______, KC_RCTL, ADJ),

    [_NUM] = LAYOUT_ansi_61_wrapper(
        _______,  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,  _______,   KC_DEL,
        _______, _______NUM_L1_______, _______NUM_R1_______,     _______,  _______,  _______,
        _______, _______, HR_S, _______, _______, KC_BSLS, _______NUM_R2_______,  _______,            _______,
        _______, _______NUM_L3_______, _______NUM_R3_______,            _______,
        _______, _______,  _______,              LGUI_T(KC_0),                             _______,  _______, _______, _______),

    [_NAV] = LAYOUT_ansi_61_wrapper(
        _______,  _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,  _______,   KC_DEL,
        _______,  _______NAV_L1_______, _______NAV_R1_______,     _______,  _______,  _______,
        _______,  _______NAV_L2_______, _______NAV_R2_______,  _______,            _______,
        _______,  _______NAV_L3_______, _______NAV_R3_______, _______,
        _______,  _______,  _______,                    _______,                             _______,  _______, _______, _______),

    // based on default keychron v4 _FN3
    // https://github.com/qmk/qmk_firmware/blob/master/keyboards/keychron/v4/ansi/keymaps/default/keymap.c
    [_ADJUST] = LAYOUT_ansi_61(
        QK_BOOT, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLU,   _______,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______,  _______, KC_VOLD,            _______,
        _______,           _______, _______, _______, KC_BRID, KC_BRIU, NK_TOGG, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            APP,                            _______,  _______,  _______,  _______),
};
// clang-format on

bool defaults[] = {};
size_t num_defaults = 0;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case APP:
      if (default_layer_state == WIN_BASE) {
        if (record->event.pressed) {
          tap_code(KC_APP);
        }
      }
      return false;
  }
  return true;
}
