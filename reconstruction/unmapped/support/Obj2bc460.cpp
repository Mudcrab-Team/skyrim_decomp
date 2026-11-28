// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc460::Function2bc460, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// 0x2bc460 Obj2bc460::Function2bc460
#include "Obj2bc460.h"

// Returns interior lighting float field 0x4C, delegating to the lighting template when inherited.
float Obj2bc460::Function2bc460() const
{
    if ((cellFlags & 0x1u) == 0 || !interiorData) {
        return 1.0f;
    }
    if ((interiorData->inheritFlags & 0x200u) != 0 && lightingTemplate) {
        return lightingTemplate->GetValue();
    }
    return interiorData->field4C;
}
