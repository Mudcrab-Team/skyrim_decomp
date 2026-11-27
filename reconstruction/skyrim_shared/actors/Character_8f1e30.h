// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Character, Character::GetFallbackDistance_140844FE0: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatStyle8f1e30, LerpFallback8f1b70, fCombatFallbackMin, fCombatFallbackMax, kRadiusScale8f1e30, Character::GetCombatStyle, Character::GetBoundRadius: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern float       fCombatFallbackMin;
extern float       fCombatFallbackMax;
extern const float kRadiusScale8f1e30;

struct CombatStyle8f1e30
{
    std::uint8_t unk00[0x6c];
    float        fallbackMult;  // 0x6c
};
static_assert(offsetof(CombatStyle8f1e30, fallbackMult) == 0x6c, "CombatStyle8f1e30::fallbackMult offset");

float LerpFallback8f1b70(float a_mult, float a_min, float a_max);

class Character
{
public:
    CombatStyle8f1e30* GetCombatStyle() const;
    float              GetBoundRadius() const;
    float              GetFallbackDistance_140844FE0() const;
};
