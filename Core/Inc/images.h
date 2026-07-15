#pragma once
#include "stdint.h"


typedef struct{
    uint16_t        *Buffer;
    const uint16_t   Width;
    const uint16_t  Height;
}image_t;

extern image_t heart16x16;
