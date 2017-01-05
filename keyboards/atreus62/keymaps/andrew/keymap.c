// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _QWERTY 1
#define _FUNC 2
#define _RESET 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* Colemak */
		{ KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS },
		{ KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,     KC_G,    KC_TRNS,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS },
		{ KC_LCTL,       KC_A,    KC_R,    KC_S,    KC_T,     KC_D,    KC_TRNS,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT },
		{ OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_DELT,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL  },
		{ KC_LGUI,       KC_LBRC, KC_RBRC, KC_LALT, MO(_FUNC),KC_BSPC, KC_ENT,   KC_SPC,  KC_LEFT,  KC_DOWN, KC_UP,  KC_RGHT, KC_GRV }
},

[_QWERTY] = { /* qwerty */
		{ KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS },
		{ KC_TRNS,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS },
		{ KC_TRNS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS },
		{ KC_TRNS,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_FUNC] = { 
		{ TO(_DEFAULT),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
		{ TO(_QWERTY),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F12,  S(KC_LBRC), S(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, S(KC_9), S(KC_0), KC_TRNS, KC_TRNS, KC_TRNS },
		{ TO(_RESET),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, KC_TRNS }
},

[_RESET] = {
		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}
};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};
