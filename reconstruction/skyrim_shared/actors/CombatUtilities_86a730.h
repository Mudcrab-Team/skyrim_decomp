// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatUtilities.cpp:577
// CombatUtilities, CalculateDistanceSquared, TESObjectREFR, GetWorldLocation, BGSWorldLocation, GetDistanceSquared: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatUtilities, CalculateDistanceSquared, BGSWorldLocation: CRASHLOGGER_PDB(59818@2026.10.24)
// pos_raw, space: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

class TESForm;

struct BGSWorldLocation
{
    std::uint8_t pos_raw[16];
    TESForm* space;

    float GetDistanceSquared(const BGSWorldLocation& a_other) const;
};
static_assert(sizeof(BGSWorldLocation) == 0x18, "BGSWorldLocation size");

class TESObjectREFR
{
public:
    BGSWorldLocation GetWorldLocation() const;
};

class CombatUtilities
{
public:
    static float CalculateDistanceSquared(const TESObjectREFR* a_ref1, const TESObjectREFR* a_ref2);  // compared: 0x86a730
};
