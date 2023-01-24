/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TAPPING_TERM 200
// #define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define ENABLE_RGB_MATRIX_NONE
// #define ENABLE_RGB_MATRIX_SOLID_COLOR               // Static single hue, no speed support
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS               // Static dual hue, speed is hue for secondary hue
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN          // Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT       // Static gradient left to right, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING                 // Single hue brightness cycling animation
// #define ENABLE_RGB_MATRIX_BAND_SAT                  // Single hue band fading saturation scrolling left to right
// #define ENABLE_RGB_MATRIX_BAND_VAL                  // Single hue band fading brightness scrolling left to right
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT         // Single hue 3 blade spinning pinwheel fades saturation
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL         // Single hue 3 blade spinning pinwheel fades brightness
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT           // Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL           // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL                 // Full keyboard solid hue cycling through full gradient
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT          // Full gradient scrolling left to right
// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN             // Full gradient scrolling top to bottom
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN              // Full gradient scrolling out to in
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL         // Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // Full gradient Chevron shapped scrolling left to right
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL            // Full gradient spinning pinwheel around center of keyboard
// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL              // Full gradient spinning spiral around center of keyboard
// #define ENABLE_RGB_MATRIX_DUAL_BEACON               // Full gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON            // Full tighter gradient spinning around center of keyboard
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS         // Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_RAINDROPS                 // Randomly changes a single key's hue
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS       // Randomly changes a single key's hue and saturation
// #define ENABLE_RGB_MATRIX_HUE_BREATHING             // Hue shifts up a slight ammount at the same time, then shifts back
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM              // Hue shifts up a slight ammount in a wave to the right, then back to the left
// #define ENABLE_RGB_MATRIX_HUE_WAVE                  // Hue shifts up a slight ammount and then back down in a wave to the right
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL             // Single hue fractal filled keys pulsing horizontally out to edges
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW                // Pulsing RGB flow along LED wiring with random hues
#define ENABLE_RGB_MATRIX_PIXEL_RAIN                // Randomly light keys with random hues

// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out

#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#define RGB_MATRIX_KEYPRESSES                       // reacts to keypresses
#define RGB_DISABLE_AFTER_TIMEOUT 0                 // number of ticks to wait until disabling effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED false        // turn off effects when suspended
#define RGB_MATRIX_LED_FLUSH_LIMIT 16               // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON