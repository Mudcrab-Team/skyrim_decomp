// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x8f31f0 Character::sub_1408463A0
// Adapted bodies: none
#include "Character_8f31f0.h"

// Compute the ranged combat distance using squared global parameters and the character's base value.
float Character::sub_1408463A0() const
{
    float base = GetBaseValue86a730();
    return ComputeRange8f1b90(
        base,
        g_fallbackParam1 * g_fallbackParam1,
        g_fallbackParam2 * g_fallbackParam2,
        g_fallbackParam3,
        g_fallbackParam4);
}
