// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc240::Function2bc240, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// ColorFloat2bc240, LightingTemplate2bc240, InteriorData2bc240, Obj2bc240: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat2bc240
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

struct LightingTemplate2bc240
{
    std::uint32_t GetColor() const;
};

struct InteriorData2bc240
{
    std::uint8_t unk00[0x48];    // 0x00
    std::uint32_t color48;       // 0x48
    std::uint8_t unk4C[0x0C];    // 0x4C
    std::uint32_t inheritFlags;  // 0x58
};

class Obj2bc240
{
public:
    void Function2bc240(ColorFloat2bc240& a_out) const;

    std::uint8_t unk00[0x40];                        // 0x00
    std::uint16_t cellFlags;                         // 0x40
    std::uint8_t unk42[0x26];                        // 0x42
    const InteriorData2bc240* interiorData;          // 0x68
    std::uint8_t unk70[0xC8];                        // 0x70
    const LightingTemplate2bc240* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bc240, color48) == 0x48, "color48 offset");
static_assert(offsetof(InteriorData2bc240, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bc240, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bc240, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bc240, lightingTemplate) == 0x138, "lightingTemplate offset");
