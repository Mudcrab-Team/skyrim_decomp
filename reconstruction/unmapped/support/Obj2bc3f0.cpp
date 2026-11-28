// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc3f0::Function2bc3f0, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// 0x2bc3f0 Obj2bc3f0::Function2bc3f0
#include "Obj2bc3f0.h"

// Returns interior lighting float field 0x24, delegating to the lighting template when inherited.
float Obj2bc3f0::Function2bc3f0() const
{
    if ((cellFlags & 0x1u) == 0 || !interiorData) {
        return 1.0f;
    }
    if ((interiorData->inheritFlags & 0x100u) != 0 && lightingTemplate) {
        return lightingTemplate->GetValue();
    }
    return interiorData->field24;
}
