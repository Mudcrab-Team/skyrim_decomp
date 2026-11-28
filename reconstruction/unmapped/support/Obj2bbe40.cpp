// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bbe40::Function2bbe40, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2bbe40 Obj2bbe40::Function2bbe40
#include "Obj2bbe40.h"

// Reads interior lighting color 0x00 (or inherited template color) as normalized RGB floats.
void Obj2bbe40::Function2bbe40(ColorFloat2bbe40& a_out) const
{
    std::uint32_t c;
    if ((cellFlags & 0x1u) != 0 && interiorData) {
        if ((interiorData->inheritFlags & 0x1u) != 0 && lightingTemplate) {
            c = lightingTemplate->GetColor();
        } else {
            c = interiorData->color00;
        }
    } else {
        c = 0u;
    }
    a_out.r = static_cast<float>(static_cast<std::uint8_t>(c)) / 255.0f;
    a_out.g = static_cast<float>(static_cast<std::uint16_t>(c) >> 8) / 255.0f;
    a_out.b = static_cast<float>(static_cast<std::uint8_t>(c >> 16)) / 255.0f;
}
