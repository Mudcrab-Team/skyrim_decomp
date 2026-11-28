// Source exposure: mixed (pinned image listing; sibling source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESRegionPoint2595a0::GetDistanceSquared, treated as adapted: shaped like TESRegionPoint::SquaredDistanceTo in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_004e0000_od.cpp:1011
// SPDX-License-Identifier: CC0-1.0
// TESRegionPoint2595a0, TESRegionPoint2595a0::GetDistanceSquared: CRASHLOGGER_PDB(59818@2026.10.24)
// x, y: GUESS(low)
#pragma once

class TESRegionPoint2595a0
{
public:
    float GetDistanceSquared(const TESRegionPoint2595a0* other) const;

    float x;  // 00
    float y;  // 04
};
