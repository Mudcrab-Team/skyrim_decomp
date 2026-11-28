// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc1b0::Function2bc1b0, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2bc1b0 Obj2bc1b0::Function2bc1b0
#include "Obj2bc1b0.h"

// Reads interior lighting color 0x08 (or inherited template color) as normalized RGB floats.
void Obj2bc1b0::Function2bc1b0(ColorFloat2bc1b0& a_out) const
{
    std::uint32_t c;
    if ((cellFlags & 0x1u) != 0 && interiorData) {
        if ((interiorData->inheritFlags & 0x4u) != 0 && lightingTemplate) {
            c = lightingTemplate->GetColor();
        } else {
            c = interiorData->color08;
        }
    } else {
        c = 0u;
    }
    a_out.r = static_cast<float>(static_cast<std::uint8_t>(c)) / 255.0f;
    a_out.g = static_cast<float>(static_cast<std::uint16_t>(c) >> 8) / 255.0f;
    a_out.b = static_cast<float>(static_cast<std::uint8_t>(c >> 16)) / 255.0f;
}
