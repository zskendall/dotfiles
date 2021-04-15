#pragma once
#include "zskendall.h"

enum dances {
  TD_TAB_BSP, TD_QP, TD_WO, TD_EI, TD_RU, TD_TY,
  TD_ESC_QUOT, TD_ASCLN, TD_SL, TD_DK, TD_FJ, TD_GH,
  TD_ART, TD_ZSLSH, TD_XDOT, TD_CCOMM, TD_VM, TD_BN,
  TD_SPC_RET,
};

void art_dance_back(qk_tap_dance_state_t *state, void *user_data);
