// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ComputeBarycentric.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp:373
// 0xf41930 ComputeBarycentric
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp:683
// Adapted helpers: Dot
#include "Globals_f41930.h"

void ComputeBarycentric(const Vec3f* apVertex0, const Vec3f* apVertex1, const Vec3f* apVertex2, const Vec3f* apPoint,
                        Vec3f* apBarycentric)
{
    Vec3f p(*apVertex0, *apVertex2);
    Vec3f v1(*apVertex1, *apVertex2);
    Vec3f r(*apPoint, *apVertex2);

    float d11 = p.Dot(p);
    float fDot01 = p.Dot(v1);
    float fDot11 = v1.Dot(v1);
    float fDot02 = p.Dot(r);
    float fDot12 = v1.Dot(r);
    float fInvDenom = 1.0f / (d11 * fDot11 - fDot01 * fDot01);
    float s = (fDot11 * fDot02 - fDot01 * fDot12) * fInvDenom;
    apBarycentric->x = s;
    float t = (d11 * fDot12 - fDot01 * fDot02) * fInvDenom;
    apBarycentric->y = t;
    apBarycentric->z = 1.0f - s - t;
}
