// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ExtraLevCreaModifier184a50::GetMultiplier, treated as adapted: shaped like ExtraLevCreaModifier::GetMultiplier in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/extradataobjects.cpp:1256
// SPDX-License-Identifier: CC0-1.0
// Setting184a50, ExtraLevCreaModifier184a50, gLevCreaMultipliers184a50: GUESS(low)
// GetMultiplier: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

struct Setting184a50
{
    void* vftable;  // 00
    float value;    // 08
};

extern Setting184a50* gLevCreaMultipliers184a50[4];

struct ExtraLevCreaModifier184a50
{
    static float GetMultiplier(std::int32_t a_modifier);  // compared: 0x184a50
};
