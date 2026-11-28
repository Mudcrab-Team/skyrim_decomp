// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc1b0::Function2bc1b0, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// ColorFloat2bc1b0, LightingTemplate2bc1b0, InteriorData2bc1b0, Obj2bc1b0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat2bc1b0
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

struct LightingTemplate2bc1b0
{
    std::uint32_t GetColor() const;
};

struct InteriorData2bc1b0
{
    std::uint32_t unk00[2];      // 0x00
    std::uint32_t color08;       // 0x08
    std::uint8_t unk0C[0x4C];    // 0x0C
    std::uint32_t inheritFlags;  // 0x58
};

class Obj2bc1b0
{
public:
    void Function2bc1b0(ColorFloat2bc1b0& a_out) const;

    std::uint8_t unk00[0x40];                        // 0x00
    std::uint16_t cellFlags;                         // 0x40
    std::uint8_t unk42[0x26];                        // 0x42
    const InteriorData2bc1b0* interiorData;          // 0x68
    std::uint8_t unk70[0xC8];                        // 0x70
    const LightingTemplate2bc1b0* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bc1b0, color08) == 0x08, "color08 offset");
static_assert(offsetof(InteriorData2bc1b0, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bc1b0, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bc1b0, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bc1b0, lightingTemplate) == 0x138, "lightingTemplate offset");
