// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bbe40::Function2bbe40, treated as adapted: shaped like an inherited cell colour reader in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:2310
// SPDX-License-Identifier: CC0-1.0
// ColorFloat2bbe40, LightingTemplate2bbe40, InteriorData2bbe40, Obj2bbe40: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ColorFloat2bbe40
{
    float r;  // 0x00
    float g;  // 0x04
    float b;  // 0x08
};

struct LightingTemplate2bbe40
{
    std::uint32_t GetColor() const;
};

struct InteriorData2bbe40
{
    std::uint32_t color00;       // 0x00
    std::uint8_t unk04[0x54];    // 0x04
    std::uint32_t inheritFlags;  // 0x58
};

class Obj2bbe40
{
public:
    void Function2bbe40(ColorFloat2bbe40& a_out) const;

    std::uint8_t unk00[0x40];                        // 0x00
    std::uint16_t cellFlags;                         // 0x40
    std::uint8_t unk42[0x26];                        // 0x42
    const InteriorData2bbe40* interiorData;          // 0x68
    std::uint8_t unk70[0xC8];                        // 0x70
    const LightingTemplate2bbe40* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bbe40, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bbe40, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bbe40, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bbe40, lightingTemplate) == 0x138, "lightingTemplate offset");
