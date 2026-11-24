// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSPrimitive.cpp:250
// 0x2137f0 BGSPrimitiveSphere::IsInside
#include "BGSPrimitiveSphere_2137f0.h"

bool BGSPrimitiveSphere::IsInside(const NiPoint3& a_point) const
{
    // The image reads the radius from the second component of the shared extents vector.
    return bounds.y * bounds.y > a_point.x * a_point.x + a_point.y * a_point.y + a_point.z * a_point.z;
}
