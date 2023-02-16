#include "quantum.h"

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJST,
  _FKEYS,
  _NUMPD
};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        if(IS_LAYER_ON(_BASE)) {
            if (clockwise){
                tap_code(KC_WH_D);
            } else{
                tap_code(KC_WH_U);
            }      
        } else {
            if (clockwise){
                tap_code16(C(KC_TAB));
            } else{
                tap_code16(S(C(KC_TAB)));
            }
        }
    } else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif
