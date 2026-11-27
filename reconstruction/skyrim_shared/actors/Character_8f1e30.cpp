// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x8f1e30 Character::GetFallbackDistance_140844FE0
// Adapted bodies: none
#include "Character_8f1e30.h"

// Compute the combat fallback distance, clamped below by the scaled bounding radius.
float Character::GetFallbackDistance_140844FE0() const
{
    CombatStyle8f1e30* style = GetCombatStyle();
    float              dist  = LerpFallback8f1b70(style->fallbackMult, fCombatFallbackMin, fCombatFallbackMax);
    float              minDist = GetBoundRadius() * kRadiusScale8f1e30;
    if (dist > minDist) {
        return dist;
    }
    return minDist;
}
