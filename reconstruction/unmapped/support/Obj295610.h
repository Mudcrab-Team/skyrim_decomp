// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj295610::Function295610, treated as adapted: shaped like TESObjectCELL::GetDataAmbientColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:19818
// SPDX-License-Identifier: CC0-1.0
// ColorFloat295610, Obj295610, Obj295610::Function295610: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat295610
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

class Obj295610
{
public:
    void Function295610(ColorFloat295610& a_out) const;

    std::uint8_t unk00[0x20];  // 0x00
    std::uint32_t color;       // 0x20
};

static_assert(offsetof(Obj295610, color) == 0x20, "color offset");
