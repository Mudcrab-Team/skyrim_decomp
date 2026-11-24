// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x8f26a0 Character::Function8f26a0
// Adapted bodies: none
#include "Character_8f26a0.h"

float Character::Function8f26a0(int a_kind)
{
    float value = GetDefensiveMult();
    float result = 0.0f;
    switch (a_kind) {
    case 24:
        result = CombatAIFormulas::Interpolate(value, gRangeLow20a2d58, gRangeHigh20a2d70);
        break;
    case 25:
        result = CombatAIFormulas::Interpolate(value, gRangeLow20a2d88, gRangeHigh20a2da0);
        break;
    }
    return result;
}
