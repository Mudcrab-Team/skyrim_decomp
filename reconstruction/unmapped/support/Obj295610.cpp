// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj295610::Function295610, treated as adapted: shaped like TESObjectCELL::GetDataAmbientColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:19818
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x295610 Obj295610::Function295610
#include "Obj295610.h"

// Converts the packed RGB COLORREF at offset 0x20 into normalized floats.
void Obj295610::Function295610(ColorFloat295610& a_out) const
{
    std::uint32_t c = color;
    a_out.r = static_cast<float>(static_cast<std::uint8_t>(c)) / 255.0f;
    a_out.g = static_cast<float>(static_cast<std::uint16_t>(c) >> 8) / 255.0f;
    a_out.b = static_cast<float>(static_cast<std::uint8_t>(c >> 16)) / 255.0f;
}
