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
};

#ifdef RGB_MATRIX_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case 1:
            rgb_matrix_set_color_all(127, 0, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(0, 0, 127);
            break;
        default:
            rgb_matrix_set_color_all(127, 0, 127);
            break;
    }
  return state;
}
#endif


/*
layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
    case 1:
        rgb_matrix_set_color_all(255,0,0);
        break;
    case 2:
        rgb_matrix_set_color_all(255,0,255);
        break;
    default:
        rgb_matrix_set_color_all(255,0,255);
        break;
    }
    return state;
}
*/