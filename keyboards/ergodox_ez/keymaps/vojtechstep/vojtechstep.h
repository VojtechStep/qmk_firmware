#ifndef _VOJTECHSTEP_KEYMAP_H__
#define _VOJTECHSTEP_KEYMAP_H__

// Use BSD Unicode input for PureGTK bindings
#define UC_PGTK UC_BSD
#define UC_M_PG UC_M_BS

// Krita default shortcuts
#define KR_ZOOMIN LCTL(KC_KP_PLUS)
#define KR_ZOOMOUT LCTL(KC_KP_MINUS)
#define KR_ZOOMRST LCTL(KC_0)
#define KR_ROTL LCTL(KC_LBRACKET)
#define KR_ROTR LCTL(KC_RBRACKET)
#define KR_ROTRST LCTL(KC_BSLASH)
#define KR_UNDO LCTL(KC_Z)
#define KR_REDO LCTL(LSFT(KC_Z))
#define KR_ERASOR KC_E
#define KR_BRBIG KC_RBRACKET
#define KR_BRSMOL KC_LBRACKET
#define KR_LAYNEW KC_INSERT
#define KR_LAYNEXT KC_PGUP
#define KR_LAYPREV KC_PGDOWN
#define KR_LAYHIDE LSFT(KC_INSERT)
#define KR_CANCEL KC_ESCAPE
#define KR_CONFIRM KC_ENTER
#define KR_DSELCT LCTL(LSFT(KC_A))
#define KR_BRUSH KC_B
#define KR_SELCT LCTL(LSFT(KC_R))
#define KR_TRANS LCTL(KC_T)
#define KR_PICK KC_P

#define UNI_L(letter) XP(letter, letter + 1)

// Krita binding helpers
#define MAKE_KRITA_NUM(NUM, KR)                                                                                             \
    const key_override_t key_krita_##NUM##_num = ko_make_with_layers(MOD_MASK_GUI, KR_NUM_##NUM, LGUI(KC_##NUM), 1 << _KL); \
    const key_override_t key_krita_##NUM##_kr  = ko_make_with_layers_and_negmods(0, KR_NUM_##NUM, KR, 1 << _KL, MOD_MASK_GUI);
#define KRITA_NUM(NUM) &key_krita_##NUM##_num, &key_krita_##NUM##_kr,

// Colors
#define CL_BLACK \
    { 0, 0, 0 }
#define CL_BEIGE \
    { 50, 153, 255 }
#define CL_PURPLE \
    { 154, 86, 255 }
#define CL_PINK \
    { 252, 119, 255 }
#define CL_RED \
    { 255, 0, 0 }
#define CL_GREEN \
    { 0, 255, 0 }
#define CL_BLUE \
    { 0, 0, 255 }

#endif
