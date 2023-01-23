#include "quantum.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case 1:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case 3:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case 4:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case 5:
            rgb_matrix_set_color_all(RGB_TEAL);
            break;
        case 6:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        default:
            rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
    }
  return state;
};

led_config_t g_led_config = {
    {
    // Key Matrix to LED Index
        { 0,          NO_LED,     NO_LED,     NO_LED    },
        { NO_LED,     NO_LED,     NO_LED,     NO_LED    },
        { NO_LED,     NO_LED,     NO_LED,     NO_LED    },
        { NO_LED,     NO_LED,     NO_LED,     NO_LED    },
        { NO_LED,     NO_LED,     NO_LED    }
    }, {
    // LED Index to Physical Position
        { 0,  0 }
    }, {
    // LED Index to Flag
        1
    }
};