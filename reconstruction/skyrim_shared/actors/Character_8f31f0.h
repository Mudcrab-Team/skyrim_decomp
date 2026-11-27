// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Character, Character::sub_1408463A0: CRASHLOGGER_PDB(59818@2026.10.24)
// Character::GetBaseValue86a730, ComputeRange8f1b90, g_fallbackParam1, g_fallbackParam2, g_fallbackParam3, g_fallbackParam4: GUESS(low)
#pragma once

extern float g_fallbackParam1;
extern float g_fallbackParam2;
extern float g_fallbackParam3;
extern float g_fallbackParam4;

float ComputeRange8f1b90(float a_base, float a_sq1, float a_sq2, float a_arg4, float a_arg5);

class Character
{
public:
    float GetBaseValue86a730() const;
    float sub_1408463A0() const;
};
