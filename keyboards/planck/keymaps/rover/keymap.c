/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public Licen_BASEse for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _SHIFT,
  _LSHIFT,
  _RSHIFT,
  _NUMBERS,
  _SYMBOLS,
  _I3,
  _FKEYS,
  _NAV,
  _MOUSE
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  BACKLIT
};

// tap-dance declarations
enum {
  TD_SHIFT_CAPS = 0
};

#define ___fn__ KC_TRNS
#define __XXX__ KC_NO

#define MT_SPC MT(MOD_LSFT, KC_SPC)
#define MT_ENT MT(MOD_RSFT, KC_ENT)

#define LT_SPC LT(_LSHIFT, KC_SPC)
#define LT_ENT LT(_RSHIFT, KC_ENT)

#define MO_NUMBERS MO(_NUMBERS)
#define MO_SYMBOLS MO(_SYMBOLS)
#define LT_ESC LT(_NUMBERS, KC_ESC)
#define LT_BSPC LT(_I3, KC_ENT) // changed temp to enter
#define LT_A LT(_NAV, KC_A)
#define LT_TAB LT(_FKEYS, KC_TAB)
#define LT_DQUOT LT(_MOUSE, S(KC_QUOT)) // not used yet, looks not working
//#define LT_ESC LT(_NUMBER, KC_ESC)
//#define LT_RALT LT(_SYMBOL, KC_A)
#define CNTR_TL TG(_MOUSE) //KC_NO
#define CNTR_TR KC_NO
#define CNTR_ML KC_NO
#define CNTR_MR KC_ENT
#define CNTR_BL TD(TD_SHIFT_CAPS)
#define CNTR_BR KC_ESC

#define BR_L1 MT(MOD_LCTL, KC_TAB) // down= left control, tap=tab
#define BR_L2 KC_LGUI
#define BR_L3 KC_LALT
#define BR_L4 OSL(_NUMBERS) // one shot NUMBURS layer
#define BR_L5 OSL(_LSHIFT) // one shot LSHIFT layer

#define BR_ML LT(_FKEYS, KC_SPC) // down= FKEYS layer, tap=space
#define BR_MR LT(_I3, KC_BSPC) // down= I3 layer, tap=backspace

#define BR_R6 OSL(_RSHIFT) // one shot RSHIFT layer
#define BR_R7 OSL(_SYMBOLS) // one shot SYMBOL layer
#define BR_R8 KC_RALT
#define BR_R9 KC_RGUI
#define BR_R0 MT(MOD_RCTL, KC_ENT) // down=right control, tap=enter

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DVORAK] = {
   {S(KC_QUOT), KC_COMM, KC_DOT,  KC_P,    KC_Y,    CNTR_TL, CNTR_TR, KC_F,    KC_G,    KC_C,    KC_R,    KC_L   },
   {LT_A,       KC_O,    KC_E,    KC_U,    KC_I,    CNTR_ML, CNTR_MR, KC_D,    KC_H,    KC_T,    KC_N,    KC_S   },
   {S(KC_SCLN), KC_Q,    KC_J,    KC_K,    KC_X,    CNTR_BL, CNTR_BR, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z   },
   {BR_L1,      BR_L2,   BR_L3,   BR_L4,   BR_L5,   BR_ML,   BR_MR,   BR_R6,   BR_R7,   BR_R8,   BR_R9,   BR_R0 },
 },

 [_SHIFT] = {
   {KC_QUOT, S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y), CNTR_TL, CNTR_TR, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L)},
   {S(KC_A), S(KC_O),    S(KC_E),   S(KC_U), S(KC_I), CNTR_ML, CNTR_MR, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
   {KC_SCLN, S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X), CNTR_BL, CNTR_BR, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z)},
   {BR_L1,   BR_L2,      BR_L3,     BR_L4,   BR_L5,   KC_SPC,  KC_BSPC, BR_R6,   BR_R7,   BR_R8,   BR_R9,   BR_R0 },
 },

 [_LSHIFT] = {
   {KC_GRV,  KC_SLSH, KC_QUES, S(KC_P), S(KC_Y), CNTR_TL,   CNTR_TR, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L)},
   {S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), CNTR_ML,   CNTR_MR, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
   {KC_SCLN, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), CNTR_BL,   CNTR_BR, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z)},
   {BR_L1,   BR_L2,   BR_L3,   BR_L4,   ___fn__, S(KC_SPC), KC_DEL,  KC_MINS, BR_R7,   BR_R8,   BR_R9,   S(KC_ENT)},
 },

 [_RSHIFT] = {
   {KC_QUOT,    S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),    CNTR_TL, CNTR_TR, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L)},
   {S(KC_A),    S(KC_O),    S(KC_E),   S(KC_U), S(KC_I),    CNTR_ML, CNTR_MR, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
   {S(KC_BSLS), S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X),    CNTR_BL, CNTR_BR, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z)},
   {BR_L1,      BR_L2,      BR_L3,     BR_L4,   S(KC_MINS), KC_SPC,  KC_BSPC, ___fn__, BR_R7,   BR_R8,   BR_R9,   BR_R0 },
 },

 [_NUMBERS] = {
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__, CNTR_TL, CNTR_TR, S(KC_EQL), KC_7,       KC_8, KC_9, S(KC_8)},
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__, CNTR_ML, CNTR_MR, KC_MINUS,  KC_4,       KC_5, KC_6, KC_SLASH},
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__, CNTR_BL, CNTR_BR, KC_DOT,    KC_1,       KC_2, KC_3, S(KC_SCLN)},
   {BR_L1,   BR_L2,   BR_L3,   ___fn__,  BR_L5,  KC_SPC,  KC_BSPC, KC_0,      KC_0,       BR_R8,BR_R9,BR_R0 },
 },

 [_SYMBOLS] = {
   {S(KC_GRAVE), S(KC_9)   , S(KC_0)   , S(KC_EQL) , __XXX__   , CNTR_TL, CNTR_TR, S(KC_1), S(KC_2), S(KC_3), S(KC_4)   , S(KC_5)},
   {__XXX__    , KC_LBRC   , KC_RBRC   , KC_MINS   , S(KC_BSLS), CNTR_ML, CNTR_MR, S(KC_6), S(KC_7), S(KC_8), S(KC_SLSH), KC_EQL},
   {__XXX__    , S(KC_LBRC), S(KC_RBRC), S(KC_MINS), KC_BSLS   , CNTR_BL, CNTR_BR, KC_SLSH, __XXX__, __XXX__, __XXX__   , __XXX__},
   {BR_L1,       BR_L2,      BR_L3,      BR_L4,      BR_L5,      KC_SPC,  KC_DEL,  KC_MINS, ___fn__, BR_R8,   BR_R9,      BR_R0 },
 },

 [_I3] = {
   {LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_DEL), LGUI(KC_PAUSE), __XXX__, __XXX__,       LGUI(KC_UP),   __XXX__,        __XXX__},
   {LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), CNTR_TL,      LCTL(KC_V),     __XXX__, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), __XXX__},
   {__XXX__   , __XXX__,    __XXX__   , __XXX__   , SGUI(KC_X), LCTL(KC_X),   LCTL(KC_C),     KC_LSFT, __XXX__,       __XXX__,       SGUI(KC_HOME),  SGUI(KC_END)},
   {BR_L1,      BR_L2,      BR_L3,      BR_L4,      KC_LSFT,    KC_SPC,       ___fn__,        KC_RSFT, BR_R7,         BR_R8,         BR_R9,          BR_R0 },
 },

 [_FKEYS] = {
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__, CNTR_TL, CNTR_TR, __XXX__, KC_F7, KC_F8, KC_F9, KC_F12},
   {KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, __XXX__, CNTR_ML, CNTR_MR, __XXX__, KC_F4, KC_F5, KC_F6, KC_F11},
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__, CNTR_BL, CNTR_BR, __XXX__, KC_F1, KC_F2, KC_F3, KC_F10},
   {BR_L1,   BR_L2,   BR_L3,   BR_L4,   KC_LSFT, ___fn__, BR_MR,   KC_RSFT, BR_R7, BR_R8, BR_R9, BR_R0 },
 },

 [_NAV] = {
   {__XXX__, __XXX__, __XXX__, __XXX__, KC_PGUP,   CNTR_TL, CNTR_TR, __XXX__, KC_HOME, KC_UP  , KC_END  , __XXX__},
   {___fn__, __XXX__, __XXX__, __XXX__, KC_PGDOWN, CNTR_ML, CNTR_MR, __XXX__, KC_LEFT, KC_DOWN, KC_RIGHT, __XXX__},
   {__XXX__, __XXX__, __XXX__, __XXX__, __XXX__,   CNTR_BL, CNTR_BR, __XXX__, __XXX__, __XXX__, __XXX__ , __XXX__},
   {BR_L1,   BR_L2,   BR_L3,   BR_L4,   KC_LSFT,   KC_TAB,  BR_MR,   BR_R6,   BR_R7,   BR_R8,   BR_R9,    BR_R0 },
 },

 [_MOUSE] = {
   {__XXX__, KC_MS_BTN1,   KC_MS_BTN3,   KC_MS_BTN2,   __XXX__, CNTR_TL, CNTR_TR, __XXX__, __XXX__,    KC_MS_UP  , __XXX__, KC_MS_WH_UP},
   {__XXX__, __XXX__,      __XXX__,      __XXX__,      __XXX__, CNTR_ML, CNTR_MR, __XXX__, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN},
   {__XXX__, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, __XXX__, CNTR_BL, CNTR_BR, __XXX__, __XXX__, __XXX__, __XXX__ , __XXX__},
   {BR_L1,   BR_L2,   BR_L3,   BR_L4,   KC_LSFT,  KC_TAB,  BR_MR,   BR_R6,   BR_R7,   BR_R8,   BR_R9,    BR_R0 },
 },




};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

//uint32_t layer_state_set_user(uint32_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
//    case SYMBOL:
//    case NUMBER:
//      return false;
    default:
      return true;
  }
}

// register simple key press
void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void shift_key(uint16_t keycode)
{
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

// .......................................................... Tap Dance One Shot

void caps(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    tap_key(KC_CAPS);
  }
  else {
    set_oneshot_mods(MOD_LSFT);
    register_code   (KC_LSFT);              // on hold down
  }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data)
{
  unregister_code(KC_LSFT);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps, caps_reset)
// Other declarations would go here, separated by commas, if you have them
};
