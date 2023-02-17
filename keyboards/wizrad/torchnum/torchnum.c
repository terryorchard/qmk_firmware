#include "quantum.h"

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

bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        case 1:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        default:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
    }
    return true;
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (clockwise){
        tap_code16(C(KC_TAB));
    } else{
        tap_code16(S(C(KC_TAB)));
    }
    return true;
}