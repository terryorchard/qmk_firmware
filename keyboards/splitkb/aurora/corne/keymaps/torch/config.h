#pragma once

#define COMBO_COUNT 24
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD_PER_KEY

// ----- RGB ANIMATIONS ----- //
#define RGBLIGHT_HUE_STEP 20
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_NONE
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT       // Static gradient left to right, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL           // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL                 // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // Full gradient Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON            // Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS                 // Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_PIXEL_RAIN                // Randomly light keys with random hues
#define ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#define RGB_MATRIX_KEYPRESSES                       // reacts to keypresses
#define RGB_DISABLE_AFTER_TIMEOUT 0                 // number of ticks to wait until disabling effects
#define RGB_MATRIX_LED_FLUSH_LIMIT 16               // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON