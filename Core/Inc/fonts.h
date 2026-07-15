/* vim: set ai et ts=4 sw=4: */
#ifndef __FONTS_H__
#define __FONTS_H__

#include <stdint.h>

typedef struct {
    const uint8_t   width;
    const uint8_t   height;
    const uint16_t  *data;
}font_t;

extern font_t Font_7x10;
extern font_t Font_11x18;
extern font_t Font_16x26;

#endif // __FONTS_H__
