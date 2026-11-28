// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj259560::DistanceTo, treated as adapted: shaped like TESRegionPoint::SquaredDistanceTo in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_004e0000_od.cpp:1011
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x259560 Obj259560::DistanceTo
#include "Obj259560.h"

#include <cmath>

// Return the Euclidean distance to another 2D point, or -1.0f if null.
float Obj259560::DistanceTo(const Obj259560* other) const
{
    if (!other)
    {
        return -1.0f;
    }
    float dx = x - other->x;
    float dy = y - other->y;
    return std::sqrtf(dx * dx + dy * dy);
}
