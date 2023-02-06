// Copyright 2023 Terry Orchard (@terryorchard)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

#define RGB_DI_PIN GP2
#define RGBLED_NUM 1
#define NOP_FUDGE 0.4
#define RGBLIGHT_HUE_STEP 12
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */

#define RGBLIGHT_SLEEP /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#define RGBLIGHT_LAYERS /* Enable lighting layers */
#define RGBLIGHT_LAYER_BLINK /* Enable lighting layer blink */
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF