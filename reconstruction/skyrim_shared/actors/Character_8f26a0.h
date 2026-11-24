// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); no members are used
// Character::Function8f26a0: GUESS(low); placeholder name kept, maps a kind (24 or 25) to an interpolated defensive value
// Character::GetDefensiveMult: CRASHLOGGER_PDB(59818@2026.10.24); callee at RVA 0x8f1b50 returning a float, the address suffix of the recorded name is dropped
// CombatAIFormulas CombatAIFormulas::Interpolate: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); callee at RVA 0x8f1b70, the three-float overload
// gRangeLow20a2d58 gRangeHigh20a2d70 gRangeLow20a2d88 gRangeHigh20a2da0: GUESS(low); float values read from the image data at the RVAs in the names
#pragma once

#include <cstdint>
#include <cstddef>

extern const float gRangeLow20a2d58;
extern const float gRangeHigh20a2d70;
extern const float gRangeLow20a2d88;
extern const float gRangeHigh20a2da0;

struct CombatAIFormulas
{
    static float Interpolate(float a_value, float a_low, float a_high);
};

class Character
{
public:
    float GetDefensiveMult();
    float Function8f26a0(int a_kind);  // compared: 0x8f26a0
};
