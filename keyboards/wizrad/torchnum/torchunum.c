#include "quantum.h"

enum layers {
    _BASE,
    _MACRO,
    _ARROW,
    _RGB
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if(IS_LAYER_ON(_ARROW)) {
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