// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj295800::Function295800, treated as adapted: shaped like TESObjectCELL::GetDataAmbientColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:19818
// SPDX-License-Identifier: CC0-1.0
// ColorFloat295800, Obj295800, Obj295800::Function295800: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat295800
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

class Obj295800
{
public:
    void Function295800(ColorFloat295800& a_out) const;

    std::uint8_t unk00[0x68];  // 0x00
    std::uint32_t color;       // 0x68
};

static_assert(offsetof(Obj295800, color) == 0x68, "color offset");
