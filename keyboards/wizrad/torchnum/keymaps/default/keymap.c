#include QMK_KEYBOARD_H
#include "quantum.h"

enum layers {
    _BASE,
    _MACRO,
    _ARROW,
    _RGB
};
enum custom_keycodes {
    LAYER_SWITCH = SAFE_RANGE,
    OPTO,
    HELP,
    SAY_LIB,
    FUN_LIB,
    WEATHER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(       // 0 — BASE: numpad
        LAYER_SWITCH,   KC_PSLS,        KC_PAST,        KC_PMNS,
        KC_P7,          KC_P8,          KC_P9,          KC_PPLS,
        KC_P4,          KC_P5,          KC_P6,          KC_WH_U,
        KC_P1,          KC_P2,          KC_P3,          KC_WH_D,
        KC_P0,          KC_PDOT,        LALT_T(KC_PENT),KC_CALC
    ),
    [1] = LAYOUT(       // 1 — MACROS: wzd_bot
        LAYER_SWITCH,   SAY_LIB,        FUN_LIB,        HELP,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        WEATHER,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_U,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_D,
        OPTO,           XXXXXXX,        KC_PENT,        QK_BOOT
    ),
    [2] = LAYOUT(       // 2 — ARROW: arrow keys
        LAYER_SWITCH,   XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        KC_UP,          XXXXXXX,        XXXXXXX,
        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_WH_U,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_WH_D,
        XXXXXXX,        XXXXXXX,        KC_PENT,        _______
    ),
    [3] = LAYOUT(       // 3 — RGB: light control
        LAYER_SWITCH,   KC_MPRV,        KC_MPLY,        KC_MNXT,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        RGB_HUI,        RGB_SAI,        RGB_VAI,        KC_WH_U,
        RGB_HUD,        RGB_SAD,        RGB_VAD,        KC_WH_D,
        RGB_M_P,        RGB_TOG,        KC_PENT,        _______
    ),
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (clockwise){
        tap_code(KC_VOLU);
    } else{
        tap_code(KC_VOLD);
    }
    return true;
}


void matrix_init_user(void) {
    rgblight_enable();
    rgb_matrix_set_color(0, RGB_WHITE);
}

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case 0:
            rgblight_set0, RGB_at(102,0,204, 0);
            break;
        case 1:
            rgblight_set0, RGB_at(204,0,0, 0);
            break;
        case 2:
            rgblight_set0, RGB_at(0,204,0, 0);
            break;
        default:
            rgblight_set0, RGB_at(255,255,255, 0);
            break;
    }
  return state;
}

                switch (layer) {
                    case 0:
                        rgb_matrix_set_color_all(RGB_PURPLE);
                        SEND_STRING("purple");
                        break;
                    case 1:
                        rgb_matrix_set_color_all(RGB_RED);
                        SEND_STRING("red");
                        break;
                    case 2:
                        rgb_matrix_set_color_all(RGB_GREEN);
                        SEND_STRING("green");
                        break;
                    default:
                        rgb_matrix_set_color_all(RGB_BLUE);
                        SEND_STRING("white");
                }
            }
*/

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case 0:
            rgb_matrix_set_color(0, RGB_PURPLE);
            break;
        case 1:
            rgb_matrix_set_color(0, RGB_RED);
            break;
        case 2:
            rgb_matrix_set_color(0, RGB_GREEN);
            break;
        default:
            rgb_matrix_set_color(0, RGB_BLUE);
            break;
    }
}

uint16_t layer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_SWITCH:
            if (record->event.pressed) {
                if (layer > 0) {
                    layer_off(layer);
                }
                layer = (layer + 1) % 4;
                if (layer > 0) {
                    layer_on(layer);
                }
            }
            return false;

        case HELP:
            if (record->event.pressed) {
                SEND_STRING("/wiz help");
            }
            return false;

        case WEATHER:
            if (record->event.pressed) {
                SEND_STRING("/wiz weather");
            }
            return false;

        case SAY_LIB:
            if (record->event.pressed) {
                SEND_STRING("/wiz say library");
            }
            return false;

        case FUN_LIB:
            if (record->event.pressed) {
                SEND_STRING("/wiz fun library");
            }
            return false;

        case OPTO:
            if (record->event.pressed) {
                SEND_STRING("opto");
                SEND_STRING(SS_TAP(X_TAB));
                SEND_STRING("opto22");
                SEND_STRING(SS_TAP(X_ENTER));
            }
            return false;

        default:
            return true;
    }
}