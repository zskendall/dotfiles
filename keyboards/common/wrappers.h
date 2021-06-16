/*
 * Wrappers for common layouts so that they can be quickly modified all at once
 * instead of having to do it for each keyboard, allowing for cleaner keymaps.
 *
 * Based on github.com/qmk/qmk_firmware/blob/master/users/drashna/wrappers.h
 */

#pragma once
#include "zskendall.h"

// clang-format off
#define _______THUMB_3______    KC_LSPO,  LALT_SPC,  NUM_LB,      NAV_RB,   META_RET,   KC_RSPC

#define ______QWERTY_L1_____    KC_Q,   KC_W,   KC_E,     KC_R,   KC_T
#define ______QWERTY_L2_____    KC_A,   KC_S,   KC_D,     KC_F,   KC_G
#define ______QWERTY_L3_____    KC_Z,   KC_X,   KC_C,     KC_V,   KC_B

#define ______QWERTY_R1_____    KC_Y,   KC_U,   KC_I,     KC_O,   KC_P
#define ______QWERTY_R2_____    KC_H,   KC_J,   KC_K,     KC_L,   KC_SCLN
#define ______QWERTY_R3_____    KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH

#define _____WORKMAN_L1_____    KC_Q,   KC_D,   KC_R,     KC_W,   KC_B
#define _____WORKMAN_L2_____    KC_A,   KC_S,   KC_H,     KC_T,   KC_G
#define _____WORKMAN_L3_____    KC_Z,   KC_X,   KC_M,     KC_C,   KC_V

#define _____WORKMAN_R1_____    KC_J,   KC_F,   KC_U,     KC_P,   KC_SCLN
#define _____WORKMAN_R2_____    KC_Y,   KC_N,   KC_E,     KC_O,   KC_I
#define _____WORKMAN_R3_____    KC_K,   KC_L,   KC_COMM,  KC_DOT, KC_SLSH

#define _______NUM_L1_______    CHDF,     KC_NO,  KC_NO,  KC_E,   KC_GRV, KC_UNDS
#define _______NUM_L2_______    _____,    KC_A,   KC_NO,  KC_D,   KC_F,   KC_BSLS
#define _______NUM_L3_______    KC_NO,    KC_NO,  KC_X,   KC_C,   KC_NO,  KC_B

#define _______NUM_R1_______    KC_PAST,  KC_7,   KC_8,   KC_9,   KC_MINS, KC_BSPC
#define _______NUM_R2_______    KC_PSLS,  KC_4,   KC_5,   KC_6,   KC_PPLS
#define _______NUM_R3_______    KC_EQL,   KC_1,   KC_2,   KC_3,   KC_DOT, KC_DEL

#define ______NUM_THUMB_____    _____,  _____,  _____,      KC_0, _____,  _____

#define _______NAV_L1_______    RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), RGUI(KC_4), RGUI(KC_5)
#define _______NAV_L2_______    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     KC_NO
#define _______NAV_L3_______    LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5)

#define _______NAV_R1_______    RGUI(KC_6), RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), RGUI(KC_0)
#define _______NAV_R2_______    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   KC_NO
#define _______NAV_R3_______    LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), KC_NO,      MS_TOG

#define ______NAV_THUMB_____    _____,  _____,  ART_TOG,      _____, _____,  _____

#define _______OPS_L1_______    RESET,    VTERM,      KC_WH_U,    KC_NO,      KC_BRIU,    KC_NO
#define _______OPS_L2_______    KC_ESC,   KC_WH_L,    KC_WH_D,    KC_WH_R,    KC_BRID,    KC_NO
#define _______OPS_L3_______    KC_NO,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MSTP,    KC_NO

#define _______OPS_R1_______    KC_F1,    KC_F2,      KC_F6,      KC_NO,      KC_VOLU,    KC_PSCR
#define _______OPS_R2_______    KC_MS_L,  KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_VOLD,    KC_NO
#define _______OPS_R3_______    KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_MUTE,    MS_TOG

#define ______OPS_THUMB_____    KC_NO,    KC_NO,      KC_NO,      KC_BTN1,    KC_BTN2,    KC_BTN3

#define ________NONE________    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO

#define _______ART_L1_______    KC_ART_00, KC_ART_01, KC_ART_02, KC_ART_03, KC_ART_04, KC_ART_05
#define _______ART_L2_______    KC_ART_10, KC_ART_11, KC_ART_12, KC_ART_13, KC_ART_14, KC_ART_15
#define _______ART_L3_______    KC_ART_20, KC_ART_21, KC_ART_22, KC_ART_23, KC_ART_24, KC_ART_25

#define _______ART_R1_______    ________NONE________, _____
#define _______ART_R2_______    ________NONE________, _____
#define _______ART_R3_______    ________NONE________, KC_NO

#define ______ART_THUMB_____    KC_ART_T1, KC_ART_T2, CTL_INS,    _____, _____, _____
