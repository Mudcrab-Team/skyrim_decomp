// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func004bbc10.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:2118
// 0x7ece60 Func004bbc10
#include "Globals_7ece60.h"

void Func004bbc10(PointBBC* point)
{
    float value = point->x * point->x + point->y * point->y + point->z * point->z;
    unsigned int* bits = (unsigned int*)&value;
    float scale;
    if (*bits == 0)
    {
        scale = 0.0f;
    }
    else
    {
        short exponent = (short)((*bits >> 23) - 127);
        *bits &= 0x7FFFFF;
        if (exponent & 1)
            *bits |= 0x800000;
        exponent >>= 1;
        *bits = g_sqrtTableBBC[*bits >> 16] | ((exponent + 127) << 23);
        scale = 1.0f / value;
    }
    point->x *= scale;
    point->y *= scale;
    point->z *= scale;
}
