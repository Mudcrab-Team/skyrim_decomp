// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESRegionPoint2595a0::GetDistanceSquared, treated as adapted: shaped like TESRegionPoint::SquaredDistanceTo in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_004e0000_od.cpp:1011
// SPDX-License-Identifier: CC0-1.0
// 0x2595a0 TESRegionPoint2595a0::GetDistanceSquared
#include "TESRegionPoint2595a0.h"

// Return the squared 2D distance to another region point, or -1 if null.
float TESRegionPoint2595a0::GetDistanceSquared(const TESRegionPoint2595a0* other) const
{
    if (!other)
    {
        return -1.0f;
    }
    float dx = x - other->x;
    float dy = y - other->y;
    return dy * dy + dx * dx;
}
