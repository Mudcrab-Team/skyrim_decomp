// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bbf30::Function2bbf30, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// ColorFloat2bbf30, LightingTemplate2bbf30, InteriorData2bbf30, Obj2bbf30: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat2bbf30
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

struct LightingTemplate2bbf30
{
    std::uint32_t GetColor() const;
};

struct InteriorData2bbf30
{
    std::uint32_t unk00;         // 0x00
    std::uint32_t color04;       // 0x04
    std::uint8_t unk08[0x50];    // 0x08
    std::uint32_t inheritFlags;  // 0x58
};

class Obj2bbf30
{
public:
    void Function2bbf30(ColorFloat2bbf30& a_out) const;

    std::uint8_t unk00[0x40];                        // 0x00
    std::uint16_t cellFlags;                         // 0x40
    std::uint8_t unk42[0x26];                        // 0x42
    const InteriorData2bbf30* interiorData;          // 0x68
    std::uint8_t unk70[0xC8];                        // 0x70
    const LightingTemplate2bbf30* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bbf30, color04) == 0x04, "color04 offset");
static_assert(offsetof(InteriorData2bbf30, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bbf30, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bbf30, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bbf30, lightingTemplate) == 0x138, "lightingTemplate offset");
