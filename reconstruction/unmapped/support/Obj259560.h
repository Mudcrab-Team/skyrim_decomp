// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj259560::DistanceTo, treated as adapted: shaped like TESRegionPoint::SquaredDistanceTo in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_004e0000_od.cpp:1011
// SPDX-License-Identifier: CC0-1.0
// Obj259560, DistanceTo: GUESS(low)
#pragma once

class Obj259560
{
public:
    float DistanceTo(const Obj259560* other) const;

    float x;  // 00
    float y;  // 04
};
