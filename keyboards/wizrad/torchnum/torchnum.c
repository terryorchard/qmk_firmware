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
    _BASE,
    _NAV,
    _ALPHA,
    _ARROW,
    _MOUSE,
    _NUMS,
    _RGB
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if(IS_LAYER_ON(_ARROW) || IS_LAYER_ON(_RGB) || IS_LAYER_ON(_NUMS)) {
        if (clockwise){
        tap_code(KC_WH_U);
        } else{
        tap_code(KC_WH_D);
        }
    } else {
        if (clockwise){
            tap_code(KC_VOLD);
        } else{
            tap_code(KC_VOLU);
        }
    }
    return true;
};


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case _BASE:
            rgblight_setrgb_at(255,0,255,0);
            break;
        case _NAV:
            rgblight_setrgb_at(127,127,127,0);
            break;
        case _ALPHA:
            rgblight_setrgb_at(255,0,0,0);
            break;
        case _ARROW:
            rgblight_setrgb_at(0,255,0,0);
            break;
        case _MOUSE:
            rgblight_setrgb_at(0,0,255,0);
            break;
        case _NUMS:
            rgblight_setrgb_at(127,0,127,0);
            break;
        case _RGB:
            rgblight_setrgb_at(0,127,255,0);
            break;
        default:
            rgblight_setrgb_at(255,255,255,0);
            break;
    }
    return state;
};
