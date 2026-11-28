// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ExtraLevCreaModifier184a50::GetMultiplier, treated as adapted: shaped like ExtraLevCreaModifier::GetMultiplier in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/extradataobjects.cpp:1256
// SPDX-License-Identifier: CC0-1.0
// 0x184a50 ExtraLevCreaModifier184a50::GetMultiplier
#include "ExtraLevCreaModifier184a50.h"

// PDB: the CrashLogger PDB names this ExtraLevCreaModifier::GetMultiplier; ExtraLevCreaModifier184a50 is a stand-in for ExtraLevCreaModifier with a partial layout.
// Returns the configured float multiplier for a modifier index 0..3, or 1.0f out of range.
float ExtraLevCreaModifier184a50::GetMultiplier(std::int32_t a_modifier)
{
    if (static_cast<std::uint32_t>(a_modifier) <= 3) {
        return gLevCreaMultipliers184a50[a_modifier]->value;
    }
    return 1.0f;
}
