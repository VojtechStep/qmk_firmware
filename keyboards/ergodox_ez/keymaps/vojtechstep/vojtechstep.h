#ifndef _VOJTECHSTEP_KEYMAP_H__
#    define _VOJTECHSTEP_KEYMAP_H__

// Use BSD Unicode input for PureGTK bindings
#    define UNICODE_MODE_PGTK UNICODE_MODE_BSD
#    define UC_PGTK UC_BSD

// Krita default shortcuts
#    define KR_ZOOMIN LCTL(KC_KP_PLUS)
#    define KR_ZOOMOUT LCTL(KC_KP_MINUS)
#    define KR_ZOOMRST LCTL(KC_0)
#    define KR_ROTL LCTL(KC_LBRC)
#    define KR_ROTR LCTL(KC_RBRC)
#    define KR_ROTRST LCTL(KC_BSLS)
#    define KR_UNDO LCTL(KC_Z)
#    define KR_REDO LCTL(LSFT(KC_Z))
#    define KR_ERASOR KC_E
#    define KR_BRBIG KC_RBRC
#    define KR_BRSMOL KC_LBRC
#    define KR_LAYNEW KC_INSERT
#    define KR_LAYNEXT KC_PGUP
#    define KR_LAYPREV KC_PGDN
#    define KR_LAYHIDE LSFT(KC_INSERT)
#    define KR_CANCEL KC_ESCAPE
#    define KR_CONFIRM KC_ENTER
#    define KR_DSELCT LCTL(LSFT(KC_A))
#    define KR_BRUSH KC_B
#    define KR_SELCT LCTL(LSFT(KC_R))
#    define KR_TRANS LCTL(KC_T)
#    define KR_PICK KC_P

#    define UNI_L(letter) UP(letter, letter + 1)

// Krita binding helpers
#    define MAKE_KRITA_NUM(NUM, KR)                                                                                             \
        const key_override_t key_krita_##NUM##_num = ko_make_with_layers(MOD_MASK_GUI, KR_NUM_##NUM, LGUI(KC_##NUM), 1 << _KL); \
        const key_override_t key_krita_##NUM##_kr  = ko_make_with_layers_and_negmods(0, KR_NUM_##NUM, KR, 1 << _KL, MOD_MASK_GUI);
#    define KRITA_NUM(NUM) &key_krita_##NUM##_num, &key_krita_##NUM##_kr

// Colors
#    define CL_BLACK \
        { 0, 0, 0 }
#    define CL_BEIGE \
        { 50, 153, 255 }
#    define CL_PURPLE \
        { 154, 86, 255 }
#    define CL_PINK \
        { 252, 119, 255 }
#    define CL_RED \
        { 255, 0, 0 }
#    define CL_GREEN \
        { 0, 255, 0 }
#    define CL_BLUE \
        { 0, 0, 255 }

#endif

// clang-format off
/*  ---- LEFT HAND ----     ---- RIGHT HAND ---- */
#define LED_LAYOUT_ergodox_pretty(                \
    L01,L02,L03,L04,L05,    R01,R02,R03,R04,R05,  \
    L11,L12,L13,L14,L15,    R11,R12,R13,R14,R15,  \
    L21,L22,L23,L24,L25,    R21,R22,R23,R24,R25,  \
    L31,L32,L33,L34,L35,    R31,R32,R33,R34,R35,  \
    L41,L42,L43,L44,            R42,R43,R44,R45 ) \
                                                  \
   /* matrix positions */                         \
    { R01, R02, R03, R04, R05,                    \
      R11, R12, R13, R14, R15,                    \
      R21, R22, R23, R24, R25,                    \
      R31, R32, R33, R34, R35,                    \
           R42, R43, R44, R45,                    \
                                                  \
      L05, L04, L03, L02, L01,                    \
      L15, L14, L13, L12, L11,                    \
      L25, L24, L23, L22, L21,                    \
      L35, L34, L33, L32, L31,                    \
           L44, L43, L42, L41                     \
    }
// clang-format on
