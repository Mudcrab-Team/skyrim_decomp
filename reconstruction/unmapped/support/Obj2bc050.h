// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc050::Function2bc050, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// InteriorData2bc050, Template2bc050, Obj2bc050, Obj2bc050::Function2bc050: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct InteriorData2bc050
{
    std::uint8_t unk00[0x18];    // 0x00
    std::uint32_t field18;       // 0x18
    std::uint8_t unk1C[0x3C];    // 0x1C
    std::uint32_t inheritFlags;  // 0x58
};

class Template2bc050
{
public:
    std::uint32_t GetValue() const;
};

class Obj2bc050
{
public:
    std::uint32_t Function2bc050() const;

    std::uint8_t unk00[0x40];          // 0x00
    std::uint8_t cellFlags;            // 0x40
    std::uint8_t unk41[0x27];          // 0x41
    InteriorData2bc050* interiorData;  // 0x68
    std::uint8_t unk70[0xC8];          // 0x70
    Template2bc050* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bc050, field18) == 0x18, "field18 offset");
static_assert(offsetof(InteriorData2bc050, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bc050, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bc050, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bc050, lightingTemplate) == 0x138, "lightingTemplate offset");
