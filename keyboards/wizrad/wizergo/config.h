// Copyright 2023 Terry Orchard (@terryorchard)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


// #define MATRIX_ROWS 4
// #define MATRIX_COLS 10
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

// #define TAPPING_TERM 125
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define SPLIT_HAND_PIN GP29