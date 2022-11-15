#include "action_layer.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "vojtechstep.h"

enum layers {
    // Base layer
    _BL = 0,
    // Symbol layer
    _SL,
    // Mouse + Media layer
    _ML,
    // Arrow layer
    _AL,
    // Czech layer
    _CL,
    // Krita layer
    _KL,
    NUM_LAYERS
};

enum custom_keycodes {
    KR_NUM_1 = EZ_SAFE_RANGE,
    KR_NUM_2,
    KR_NUM_3,
    KR_NUM_4,
    KR_NUM_5,
    KR_NUM_6,
    KR_NUM_7,
    KR_NUM_8,
    KR_NUM_9,
    KR_NUM_0,
};

enum unicode_names {
    E_ACUTE,
    E_ACUTE_UP,
    E_CARET,
    E_CARET_UP,
    R_CARET,
    R_CARET_UP,
    T_CARET,
    T_CARET_UP,
    Y_ACUTE,
    Y_ACUTE_UP,
    U_ACUTE,
    U_ACUTE_UP,
    U_RING,
    U_RING_UP,
    I_ACUTE,
    I_ACUTE_UP,
    O_ACUTE,
    O_ACUTE_UP,
    A_ACUTE,
    A_ACUTE_UP,
    S_CARET,
    S_CARET_UP,
    D_CARET,
    D_CARET_UP,
    Z_CARET,
    Z_CARET_UP,
    C_CARET,
    C_CARET_UP,
    N_CARET,
    N_CARET_UP,
};

//[LAYER] = LAYOUT_ergodox_pretty(
//  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//                                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT,
//                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
//),
// clang-format off
const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_ergodox_pretty(
    MO(_ML),        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(_KL),                                        TG(_SL),        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    KC_CAPS,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           MO(_SL),                                        TG(_ML),        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           LGUI(KC_EQUAL),
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_LSHIFT,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_B,           KC_V,           KC_HOME,                                        KC_END,         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLASH,
    MO(_AL),        KC_LSHIFT,      KC_TRANSPARENT, LCAG(KC_NO),    LALT_T(KC_ESCAPE),                                                                                              RCTL_T(KC_COMMA),KC_SYSTEM_WAKE,KC_TRANSPARENT, MO(_CL),        MO(_SL),
                                                                                                    KC_WWW_BACK,    KC_WWW_FORWARD, KC_PGUP,        KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_PGDOWN,
                                                                                    KC_SPACE,       LGUI_T(KC_TAB), LGUI(KC_SPACE), KC_DELETE,      KC_ENTER,       KC_BSPACE
  ),
  [_SL] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_F12,         KC_HASH,        KC_TILD,        KC_LCBR,        KC_QUOTE,       KC_RCBR,        KC_SPACE,                                       KC_TRANSPARENT, KC_NO,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_DLR,         KC_LPRN,        KC_AMPERSAND,   KC_RPRN,                                                                        KC_NO,          KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_AT,          KC_RBRACKET,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,                                                                                                        KC_0,           KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_EQUAL,       KC_MINUS,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_ML] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_KANA,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,                                                    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_MS_ACCEL0,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_STOP,                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN2,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1
  ),
  [_AL] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LED_LEVEL,      KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,                                                                                                        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    RGB_SPD,        RGB_SPI,        RGB_MODE_REVERSE,RGB_MODE_FORWARD,
                                                                                                                    RGB_VAI,        RGB_HUI,
                                                                                    TOGGLE_LAYER_COLOR,RGB_TOG,     RGB_VAD,        RGB_HUD,        RGB_MODE_RAINBOW, RGB_MODE_PLAIN
  ),
  [_CL] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, UC_M_LN,        UC_M_WC,        UC_M_PG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, UNI_L(E_CARET), UNI_L(E_ACUTE), UNI_L(R_CARET), UNI_L(T_CARET), KC_TRANSPARENT,                                 KC_TRANSPARENT, UNI_L(Y_ACUTE), UNI_L(U_ACUTE), UNI_L(I_ACUTE), UNI_L(O_ACUTE), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, UNI_L(A_ACUTE), UNI_L(S_CARET), UNI_L(D_CARET), KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, UNI_L(U_RING),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, UNI_L(Z_CARET), KC_TRANSPARENT, UNI_L(C_CARET), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, UNI_L(N_CARET), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_KL] = LAYOUT_ergodox_pretty(
    KR_DSELCT,      KR_NUM_1,       KR_NUM_2,       KR_NUM_3,       KR_NUM_4,       KR_NUM_5,       TG(_KL),                                        KC_NO,          KR_NUM_6,       KR_NUM_7,       KR_NUM_8,       KR_NUM_9,       KR_NUM_0,       KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KR_BRSMOL,      KR_BRBIG,       KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KR_ERASOR,      KC_NO,          KR_ZOOMOUT,     KR_ZOOMIN,      KR_ZOOMRST,                                                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KR_ROTL,        KR_ROTR,        KR_ROTRST,      KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KR_REDO,        KC_NO,          KC_NO,          KC_NO,          KR_CANCEL,                                                                                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KR_LAYNEXT,     KR_LAYPREV,     KC_NO,          KC_NO,
                                                                                                                    KR_LAYNEW,      KC_NO,
                                                                                    KR_UNDO,        LGUI_T(KR_CONFIRM),KR_LAYHIDE,  KC_NO,          KC_ENTER,       KC_NO
  ),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

// clang-format off
const uint8_t PROGMEM ledmap[NUM_LAYERS][DRIVER_LED_TOTAL][3] = {
    [_ML] = LED_LAYOUT_ergodox_pretty(
      CL_RED,    CL_GREEN,  CL_BLUE,   CL_BLACK,  CL_BLACK,      CL_BEIGE,  CL_BEIGE,  CL_PURPLE, CL_PURPLE, CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,      CL_BEIGE,  CL_BEIGE,  CL_PURPLE, CL_PURPLE, CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_PURPLE, CL_PURPLE, CL_PURPLE,     CL_PINK,   CL_PINK,   CL_PINK,   CL_PINK,   CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,      CL_BLACK,  CL_PURPLE, CL_BLACK,  CL_BLACK,  CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,                            CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK
    ),

    [_AL] = LED_LAYOUT_ergodox_pretty(
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK, CL_BLACK,       CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BEIGE,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK, CL_BLACK,       CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_PURPLE, CL_BLACK, CL_BLACK,       CL_PURPLE, CL_PURPLE, CL_PURPLE, CL_PURPLE, CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK, CL_BLACK,       CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,
      CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK,                            CL_BLACK,  CL_BLACK,  CL_BLACK,  CL_BLACK
    ),
};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    uint8_t layer = biton32(layer_state);
    if (layer == _ML || layer == _AL) {
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
}

const key_override_t key_binop    = ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPERSAND, KC_PIPE, 1 << _SL);
const key_override_t key_at_grave = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT, KC_GRAVE, 1 << _SL);

MAKE_KRITA_NUM(1, KR_BRUSH);
MAKE_KRITA_NUM(2, KR_SELCT);
MAKE_KRITA_NUM(3, KR_TRANS);
MAKE_KRITA_NUM(4, KR_PICK);
MAKE_KRITA_NUM(5, KC_NO);
MAKE_KRITA_NUM(6, KC_NO);
MAKE_KRITA_NUM(7, KC_NO);
MAKE_KRITA_NUM(8, KC_NO);
MAKE_KRITA_NUM(9, KC_NO);
MAKE_KRITA_NUM(0, KC_NO);

const key_override_t **key_overrides = (const key_override_t *[]){&key_binop, &key_at_grave, KRITA_NUM(1) KRITA_NUM(2) KRITA_NUM(3) KRITA_NUM(4) KRITA_NUM(5) KRITA_NUM(6) KRITA_NUM(7) KRITA_NUM(8) KRITA_NUM(9) KRITA_NUM(0) NULL};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
    return state;
};

// Clang-format tries to put these all on the same line
// clang-format off
const uint32_t PROGMEM unicode_map[] = {
    [E_ACUTE] = 0xe9,
    [E_ACUTE_UP] = 0xc9,
    [E_CARET] = 0x11b,
    [E_CARET_UP] = 0x11a,
    [R_CARET] = 0x159,
    [R_CARET_UP] = 0x158,
    [T_CARET] = 0x165,
    [T_CARET_UP] = 0x164,
    [Y_ACUTE] = 0xfd,
    [Y_ACUTE_UP] = 0xdd,
    [U_ACUTE] = 0xfa,
    [U_ACUTE_UP] = 0xda,
    [U_RING] = 0x16f,
    [U_RING_UP] = 0x16e,
    [I_ACUTE] = 0xed,
    [I_ACUTE_UP] = 0xcd,
    [O_ACUTE] = 0xf3,
    [O_ACUTE_UP] = 0xd3,
    [A_ACUTE] = 0xe1,
    [A_ACUTE_UP] = 0xc1,
    [S_CARET] = 0x161,
    [S_CARET_UP] = 0x160,
    [D_CARET] = 0x10f,
    [D_CARET_UP] = 0x10e,
    [Z_CARET] = 0x17e,
    [Z_CARET_UP] = 0x17d,
    [C_CARET] = 0x10d,
    [C_CARET_UP] = 0x10c,
    [N_CARET] = 0x148,
    [N_CARET_UP] = 0x147,
};
// clang-format on

extern unicode_config_t unicode_config;
extern uint8_t          unicode_saved_mods;
extern bool             unicode_saved_caps_lock;
extern bool             unicode_saved_num_lock;

void unicode_input_start() {
    unicode_saved_caps_lock = host_keyboard_led_state().caps_lock;
    unicode_saved_num_lock  = host_keyboard_led_state().num_lock;

    if (unicode_config.input_mode == UC_LNX && unicode_saved_caps_lock) {
        tap_code(KC_CAPS_LOCK);
    }

    unicode_saved_mods = get_mods();
    clear_mods();

    switch (unicode_config.input_mode) {
        case UC_LNX:
            tap_code16(UNICODE_KEY_LNX);
            break;
        case UC_PGTK:
            register_code(KC_LEFT_CTRL);
            register_code(KC_LEFT_SHIFT);
            tap_code(KC_U);
            break;
        case UC_WINC:
            tap_code(UNICODE_KEY_WINC);
            tap_code(KC_U);
            break;
    }

    wait_ms(UNICODE_TYPE_DELAY);
}

void unicode_input_finish() {
    switch (unicode_config.input_mode) {
        case UC_LNX:
            tap_code(KC_SPACE);
            if (unicode_saved_caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UC_PGTK:
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_LEFT_CTRL);
            tap_code(KC_SPACE);
            tap_code(KC_BACKSPACE);
            if (unicode_saved_caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UC_WINC:
            tap_code(KC_ENTER);
            break;
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods
}
void unicode_input_cancel() {
    switch (unicode_config.input_mode) {
        case UC_LNX:
            tap_code(KC_ESCAPE);
            if (unicode_saved_caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UC_PGTK:
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_LEFT_CTRL);
            tap_code(KC_ESCAPE);
            if (unicode_saved_caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UC_WINC:
            tap_code(KC_ESCAPE);
            break;
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods
}
