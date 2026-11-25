// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: AddScaledPoints.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a60000_o2.cpp:4784
// 0xf05f30 AddScaledPoints
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:3988
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2_2.cpp:794
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:23539
// Adapted helpers: operator*, operator+=
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
