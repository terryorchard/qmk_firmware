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

#include "quantum.h"

// The first four layers gets a name for readability, which is then used in the OLED below.

enum layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _NUMS,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            rgblight_setrgb(RGB_RED);
            break;
        case _LOWER:
            rgblight_setrgb(RGB_GREEN);
            break;
        case _NUMS:
            rgblight_setrgb(RGB_BLUE);
            break;
        default:
            rgblight_setrgb(RGB_WHITE);
            break;
    }
    return state;
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if(IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_NUMS)) {
        if (clockwise){
        tap_code(KC_WH_D);
        } else{
        tap_code(KC_WH_U);
        }
    } else {
        if (clockwise){
            tap_code(KC_VOLU);
        } else{
            tap_code(KC_VOLD);
        }
    }
    return true;
}