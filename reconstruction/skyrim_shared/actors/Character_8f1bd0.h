// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: GUESS(low); placeholder class kept, the function takes no object (the name source puts it in CombatAIFormulas)
// Character::Interpolate: CRASHLOGGER_PDB(59818@2026.10.24); a three-point interpolation over a parameter in -1..1
#pragma once

#include <cstdint>
#include <cstddef>

class Character
{
public:
    static float Interpolate(float a_t, float a_low, float a_mid, float a_high);  // compared: 0x8f1bd0
};
