// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a42070.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a40000_o2.cpp:532
// 0xf98ab0 Func00a42070
#include "Globals_f98ab0.h"

float Func00a42070(float arg1, float arg2, float arg3, float arg4, float arg5)
{
    float fTerm1 = (arg5 + arg3) - (arg4 - arg2) * 2.0f;
    float fTerm2 = (arg4 - arg2) * 3.0f - (arg3 * 2.0f + arg5);
    return arg2 + ((arg1 * fTerm1 + fTerm2) * arg1 + arg3) * arg1;
}
