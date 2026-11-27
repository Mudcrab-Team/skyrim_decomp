// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2a0ef0 BGSWorldLocation::GetDistanceSquared
// Adapted bodies: BGSWorldLocation::GetDistanceSquared follows fo4-private@1b765c70 src/Shared/TESForms/World/BGSWorldLocation.cpp:110
#include "BGSWorldLocation_2a0ef0.h"

#include <cfloat>

float BGSWorldLocation::GetDistanceSquared(const BGSWorldLocation& arWorldLocation) const
{
    if (pSpace != arWorldLocation.pSpace)
        return FLT_MAX;
    float dx = arWorldLocation.Point.x - Point.x;
    float dy = arWorldLocation.Point.y - Point.y;
    float dz = arWorldLocation.Point.z - Point.z;
    return dy * dy + dx * dx + dz * dz;
}
