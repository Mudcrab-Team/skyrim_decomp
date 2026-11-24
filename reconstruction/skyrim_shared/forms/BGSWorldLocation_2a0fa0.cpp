// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2a0fa0 BGSWorldLocation::GetModifiedDistanceSquared
// Adapted bodies: BGSWorldLocation::GetModifiedDistanceSquared follows fo4-private@1b765c70 src/Shared/TESForms/World/BGSWorldLocation.cpp:132
#include "BGSWorldLocation_2a0fa0.h"

#include <cfloat>

float BGSWorldLocation::GetModifiedDistanceSquared(const BGSWorldLocation& arWorldLocation, const NiPoint3& arCoordMult) const
{
    if (pSpace != arWorldLocation.pSpace)
        return FLT_MAX;
    float dx = (arWorldLocation.Point.x - Point.x) * arCoordMult.x;
    float dy = (arWorldLocation.Point.y - Point.y) * arCoordMult.y;
    float dz = (arWorldLocation.Point.z - Point.z) * arCoordMult.z;
    return dx * dx + dy * dy + dz * dz;
}
