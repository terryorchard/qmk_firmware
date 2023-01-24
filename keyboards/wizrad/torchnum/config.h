// Copyright 2023 Terry Orchard (@terryorchard)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef RGBLIGHT_ENABLE
    #define NOP_FUDGE 0.4
    #define RGBLED_NUM 1
    #define RGBLIGHT_HUE_STEP 12
    #define RGBLIGHT_SAT_STEP 8
    #define RGB_DI_PIN GP0
#endif