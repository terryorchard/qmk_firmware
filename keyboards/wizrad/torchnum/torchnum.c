#include "quantum.h"
/*
led_config_t g_led_config = { {
        // Key Matrix to LED Index,
        { 0,      NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED },
        { NO_LED, NO_LED, NO_LED, NO_LED }
    }, {
        // LED Index to Physical Position
        { 0,  0 }
    }, {
        // LED Index to Flag
        0
    }
};

// get_highest_layer(layer_state|default_layer_state)
bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    switch(biton32(layer_state)) {
        case 0:
            rgb_matrix_set_color(0, RGB_RED);
            break;
        default:
            rgb_matrix_set_color(0, RGB_WHITE);
    }
    return true;
}
*/

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (biton32(layer_state) == 0) {
        if (clockwise){
            tap_code16(C(KC_TAB));
        } else{
            tap_code16(S(C(KC_TAB)));
        }
        return true;
    } else {
        if (clockwise){
            tap_code16(KC_VOLU);
        } else{
            tap_code16(KC_VOLD);
        }
        return true;
    }

}
