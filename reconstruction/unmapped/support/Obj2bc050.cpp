// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc050::Function2bc050, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// 0x2bc050 Obj2bc050::Function2bc050
#include "Obj2bc050.h"

// Returns interior lighting field 0x18, delegating to the lighting template when inherited.
std::uint32_t Obj2bc050::Function2bc050() const
{
    if ((cellFlags & 0x1u) == 0 || !interiorData) {
        return 0u;
    }
    if ((interiorData->inheritFlags & 0x20u) != 0 && lightingTemplate) {
        return lightingTemplate->GetValue();
    }
    return interiorData->field18;
}
