#pragma once

/* Use I2C or Serial, not both */

// #define USE_SERIAL_PD2
// #define USE_MATRIX_I2C
#define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

/* Mouse key tweaks */
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// Prevent fast combos registering as mods
#define IGNORE_MOD_TAP_INTERRUPT
