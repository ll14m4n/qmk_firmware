#include QMK_KEYBOARD_H
#include <stdio.h>
#include "wrappers.h"

// extern uint8_t is_master;

enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_QWER = SAFE_RANGE, KC_COLE };


// layer
#define LOW_SPC LT(_LOWER, KC_SPACE)
//#define RAI_ENT  LT(_RAISE, KC_ENT)
#define RAISE MO(_RAISE)

// modifiers
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTRL OSM(MOD_RCTL)
#define OS_MEH OSM(MOD_MEH)    // focus apps, slate window manager
#define OS_HYPR OSM(MOD_HYPR)
//#define MEH_     MT(MOD_MEH,KC_NO)

// mac os
#define CH_LANG KC_F13         // mapped to select prev input lang in macOS
#define ALFRED  KC_F14
#define CLIPBRD KC_F15         // Alfred's snippets/clipboard history
#define PREV_TB SCMD(KC_LBRC)  // cmd+shift+[
#define NEXT_TB SCMD(KC_RBRC)  // cmd+shift+]
#define BACK    LCMD(KC_LBRC)  // cmd+[
#define FORWARD LCMD(KC_RBRC)  // cmd+]

// @formatter:off
// clang-format off


#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_wrapper(
      KC_GESC,  ________________NUMBER_LEFT________________,                  ________________NUMBER_RIGHT_______________, KC_RBRC,
      KC_TAB,   _________________QWERTY_L1_________________,                  _________________QWERTY_R1_________________, KC_LBRC,
      OS_LCTRL, _________________QWERTY_L2_________________,                  _________________QWERTY_R2_________________, KC_QUOT,
      OS_LSFT,  _________________QWERTY_L3_________________, KC_COLE, CH_LANG,_________________QWERTY_R3_________________, OS_RSFT,
                                 KC_RCTRL, KC_LALT, KC_LGUI, LOW_SPC, KC_ENT, RAISE,  KC_BSPC, OS_MEH
    ),

    [_COLEMAK] = LAYOUT_wrapper(
      _______, ___________________________________________,                   ___________________________________________, _______,
      _______, _________________COLEMAK_L1________________,                   _________________COLEMAK_R1________________, _______,
      _______, _________________COLEMAK_L2________________,                   _________________COLEMAK_R2________________, _______,
      _______, _________________COLEMAK_L3________________, KC_QWER, _______, _________________COLEMAK_R3________________, _______,
                                 _______, _______, _______, _______, _______, _______,  _______, _______
    ),

    [_LOWER] = LAYOUT_wrapper(
      XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,                   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,                   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXX,
      _______, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,                   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, _______,
      _______, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, ALFRED,  _______, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, XXXXXXX,
      _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX, KC_F15,  XXXXXXX, XXXXXXX, PREV_TB, NEXT_TB, BACK,    FORWARD, _______,
                                 _______, _______, _______, _______, _______, _______, KC_DEL,  XXXXXXX
    ),

    [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, _______, _______,  _______, _______, _______
    )
};

// @formatter:on
// clang-format on

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_ln_P(PSTR("Default"), false);
                break;
            case _RAISE:
                oled_write_ln_P(PSTR("Raise"), false);
                break;
            case _LOWER:
                oled_write_ln_P(PSTR("Lower"), false);
                break;
            case _ADJUST:
                oled_write_ln_P(PSTR("Adjust"), false);
                break;
            default:
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        oled_write_ln("", false);

    } else {
        render_logo();
    }
    return false;
}
#endif  // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_COLE:
            if (record->event.pressed && !get_mods()) {
                default_layer_set(1UL << _COLEMAK);
                tap_code(KC_F13);
#ifdef OLED_ENABLE
                if (is_keyboard_master()) {
                    oled_write_ln_P(PSTR("COLEMAK"), false);
                }
#endif
            }
            break;

        case KC_QWER:
            if (record->event.pressed && !get_mods()) {
                default_layer_set(1UL << _QWERTY);
                tap_code(KC_F13);
#ifdef OLED_ENABLE
                if (is_keyboard_master()) {
                    oled_write_ln_P(PSTR("QWERTY"), false);
                }
#endif
            }
            break;

        default:
            break;
    }
    return true;
}

// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {  // Encoder on master side
        if (IS_LAYER_ON(_LOWER)) {
            // Cursor control
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    //  else if (index == 0) { // Encoder on slave side
    //    if(IS_LAYER_ON(_LOWER)) { // on Lower layer
    //      //
    //      if (clockwise) {
    //          tap_code(KC_RIGHT);
    //      } else {
    //          tap_code(KC_LEFT);
    //      }
    //    }
    //    else {
    //      if (clockwise) {
    //          tap_code(KC_DOWN);
    //      } else {
    //          tap_code(KC_UP);
    //      }
    //    }
    //  }
    return true;
}
#endif
