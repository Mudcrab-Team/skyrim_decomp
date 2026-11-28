// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj295800::Function295800, treated as adapted: shaped like TESObjectCELL::GetDataAmbientColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:19818
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x295800 Obj295800::Function295800
#include "Obj295800.h"

// Converts the packed RGB COLORREF at offset 0x68 into normalized floats.
void Obj295800::Function295800(ColorFloat295800& a_out) const
{
    std::uint32_t c = color;
    a_out.r = static_cast<float>(static_cast<std::uint8_t>(c)) / 255.0f;
    a_out.g = static_cast<float>(static_cast<std::uint16_t>(c) >> 8) / 255.0f;
    a_out.b = static_cast<float>(static_cast<std::uint8_t>(c >> 16)) / 255.0f;
}
