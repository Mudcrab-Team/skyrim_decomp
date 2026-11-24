// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/BGSWorldLocation.cpp:132
// BGSWorldLocation, BGSWorldLocation::GetModifiedDistanceSquared, BGSWorldLocation::Point, BGSWorldLocation::pSpace, NiPoint3, TESForm: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to the members the body uses
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class TESForm;

class BGSWorldLocation
{
public:
    float GetModifiedDistanceSquared(const BGSWorldLocation& arWorldLocation, const NiPoint3& arCoordMult) const;

    NiPoint3  Point;   // 00
    TESForm*  pSpace;  // 10
};
