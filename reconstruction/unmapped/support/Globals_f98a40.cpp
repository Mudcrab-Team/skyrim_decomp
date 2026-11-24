// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a42070.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a40000_o2.cpp:532
// 0xf98a40 Func00a42070
#include "Globals_f98a40.h"

float Func00a42070(float param_1, float param_2, float param_3, float param_4, float param_5)
{
    float fTerm1 = (param_5 + param_3) - (param_4 - param_2) * 2.0f;
    float fTerm2 = (param_4 - param_2) * 3.0f - (param_3 * 2.0f + param_5);
    return param_2 + ((param_1 * fTerm1 + fTerm2) * param_1 + param_3) * param_1;
}
