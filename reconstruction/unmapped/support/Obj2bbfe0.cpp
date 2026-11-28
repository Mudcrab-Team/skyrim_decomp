// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bbfe0::Function2bbfe0, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// 0x2bbfe0 Obj2bbfe0::Function2bbfe0
#include "Obj2bbfe0.h"

// Returns interior lighting field 0x14, delegating to the lighting template when inherited.
std::uint32_t Obj2bbfe0::Function2bbfe0() const
{
    if ((cellFlags & 0x1u) == 0 || !interiorData) {
        return 0u;
    }
    if ((interiorData->inheritFlags & 0x20u) != 0 && lightingTemplate) {
        return lightingTemplate->GetValue();
    }
    return interiorData->field14;
}
