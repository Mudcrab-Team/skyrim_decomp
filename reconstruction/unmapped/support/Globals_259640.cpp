// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func004a23f0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004a0000_o2.cpp:4946
// 0x259640 Func004a23f0
#include "Globals_259640.h"

float Func004a23f0(float* first, float* second, float value)
{
    if (first != 0 && second != 0)
    {
        float secondX = second[0];
        float secondY = second[1];
        return secondX - ((first[0] - secondX) / (first[1] - secondY)) * (secondY - value);
    }
    return 0.0f;
}
