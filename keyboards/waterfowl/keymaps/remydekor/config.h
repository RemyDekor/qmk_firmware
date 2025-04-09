#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define COMBO_COUNT 7

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD_PER_KEY // counter-productive for my typing style
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define MOUSEKEY_DELAY 55
#define MOUSEKEY_INTERVAL 13
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_TIME_TO_MAX 28
