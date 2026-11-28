// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj295690::Function295690, treated as adapted: shaped like TESObjectCELL::GetDataAmbientColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:19818
// SPDX-License-Identifier: CC0-1.0
// ColorFloat295690, Obj295690, Obj295690::Function295690: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat295690
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

class Obj295690
{
public:
    void Function295690(ColorFloat295690& a_out) const;

    std::uint8_t unk00[0x24];  // 0x00
    std::uint32_t color;       // 0x24
};

static_assert(offsetof(Obj295690, color) == 0x24, "color offset");
