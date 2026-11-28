// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc460::Function2bc460, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// InteriorData2bc460, Template2bc460, Obj2bc460, Obj2bc460::Function2bc460: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct InteriorData2bc460
{
    std::uint8_t unk00[0x4C];    // 0x00
    float field4C;               // 0x4C
    std::uint8_t unk50[0x08];    // 0x50
    std::uint32_t inheritFlags;  // 0x58
};

class Template2bc460
{
public:
    float GetValue() const;
};

class Obj2bc460
{
public:
    float Function2bc460() const;

    std::uint8_t unk00[0x40];          // 0x00
    std::uint8_t cellFlags;            // 0x40
    std::uint8_t unk41[0x27];          // 0x41
    InteriorData2bc460* interiorData;  // 0x68
    std::uint8_t unk70[0xC8];          // 0x70
    Template2bc460* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bc460, field4C) == 0x4C, "field4C offset");
static_assert(offsetof(InteriorData2bc460, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bc460, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bc460, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bc460, lightingTemplate) == 0x138, "lightingTemplate offset");
