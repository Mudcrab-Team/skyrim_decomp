// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: AddScaledPoints.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a60000_o2.cpp:4784
// 0xf05f30 AddScaledPoints
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a60000_o2.cpp:3826
#include "Globals_f05f30.h"

void AddScaledPoints(NiPoint3* dest, float scale, const NiPoint3* src, unsigned int count)
{
    Vec3* d = reinterpret_cast<Vec3*>(dest);
    const Vec3* s = reinterpret_cast<const Vec3*>(src);
    for (unsigned int i = 0; i < count; ++i)
    {
        d[i] += s[i] * scale;
    }
}
