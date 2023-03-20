// Copyright 2023 Terry Orchard (@terryorchard)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 10
#define SPLIT_HAND_PIN GP29

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define COMBO_COUNT 23

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Tapping while holding sends hold key even within the tapping term.
#define PERMISSIVE_HOLD

// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP
