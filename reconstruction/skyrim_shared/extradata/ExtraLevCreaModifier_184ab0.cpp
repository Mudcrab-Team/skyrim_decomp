// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x184ab0 ExtraLevCreaModifier::Function184ab0
// Adapted bodies: none
#include "ExtraLevCreaModifier_184ab0.h"

int ExtraLevCreaModifier::Function184ab0()
{
    switch (modifier) {
    case LEV_CREA_MODIFIER::kEasy:
        return 1;
    case LEV_CREA_MODIFIER::kVeryHard:
        return 2;
    case LEV_CREA_MODIFIER::kNone:
        return 0;
    default:
        return -1;
    }
}
