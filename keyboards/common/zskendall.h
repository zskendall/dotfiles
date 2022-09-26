#pragma once

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "wrappers.h"

#ifdef TAP_DANCE_ENABLE
#    include "tap_dances.h"
#endif

enum layers {
  _QWERTY,
  _COLEMAK,
  _WORKMAN,
  _QWORF, // _WORKMAN and _CAIN inspired
  _CAIN, // inspired by keyboard-design.com/letterlayout.html?layout=chia.en.matrix
  _NUM,
  _NAV,
  _MOUSE,
  _ART,
  _ADJUST, // for RGB stuff
};

extern bool defaults[];
extern size_t num_defaults;

enum keycodes {
  CHDF = SAFE_RANGE, // change default layer
  KEYMAP_SAFE_RANGE, // use for keymaps specific codes
};

/* Key aliases */
#define _____ KC_TRNS
#define MS_TOG TG(_MOUSE)
#define ART_TOG TG(_ART)
#define VTERM LCTL(S(KC_F1))
#define TERM LGUI(KC_ENT)
#define CMAK TG(_COLEMAK)

/** Dynamic mod-tap keycode macros. */
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_QUOT RCTL_T(KC_QUOT)
#define LALT_SPC LALT_T(KC_SPC)
#define META_RET RGUI_T(KC_ENT)
#define CTL_INS LCTL_T(KC_INS)

/** Dynamic layer-tap keycode macros. */
#define NUM_LB LT(_NUM, KC_LBRC)
#define NAV_RB LT(_NAV, KC_RBRC)

/*
 * Custom Keycodes for tap dances.
 * Since TD() only works when tap dance is enabled, use custom codes so the
 * correct things are substituted in.
 */
#ifdef TAP_DANCE_ENABLE
#    define KC_ART_00 TD(TD_TAB_BSP)
#    define KC_ART_01 TD(TD_QP)
#    define KC_ART_02 TD(TD_WO)
#    define KC_ART_03 TD(TD_EI)
#    define KC_ART_04 TD(TD_RU)
#    define KC_ART_05 TD(TD_TY)
#    define KC_ART_10 TD(TD_ESC_QUOT)
#    define KC_ART_11 TD(TD_ASCLN)
#    define KC_ART_12 TD(TD_SL) 
#    define KC_ART_13 TD(TD_DK)
#    define KC_ART_14 TD(TD_FJ)
#    define KC_ART_15 TD(TD_GH)
#    define KC_ART_20 TD(TD_HYUND_EXIT)
#    define KC_ART_21 TD(TD_ZSLSH)
#    define KC_ART_22 TD(TD_XDOT)
#    define KC_ART_23 TD(TD_CCOMM)
#    define KC_ART_24 TD(TD_VM)
#    define KC_ART_25 TD(TD_BN)
#    define KC_ART_T1 KC_LSFT
#    define KC_ART_T2 TD(TD_SPC_RET)
# else
#    define KC_ART_00 ART_TOG
#    define KC_ART_01 KC_N
#    define KC_ART_02 KC_W
#    define KC_ART_03 KC_E
#    define KC_ART_04 KC_O
#    define KC_ART_05 KC_T
#    define KC_ART_10 _____
#    define KC_ART_11 KC_A
#    define KC_ART_12 KC_S
#    define KC_ART_13 KC_D
#    define KC_ART_14 KC_J
#    define KC_ART_15 KC_G
#    define KC_ART_20 KC_LSFT
#    define KC_ART_21 KC_Z
#    define KC_ART_22 KC_X
#    define KC_ART_23 KC_C
#    define KC_ART_24 KC_V
#    define KC_ART_25 KC_B
#    define KC_ART_T1 _____
#    define KC_ART_T2 _____
#endif // TAP_DANCE_ENABLE
