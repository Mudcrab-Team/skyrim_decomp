// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bbfe0::Function2bbfe0, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// InteriorData2bbfe0, Template2bbfe0, Obj2bbfe0, Obj2bbfe0::Function2bbfe0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct InteriorData2bbfe0
{
    std::uint8_t unk00[0x14];    // 0x00
    std::uint32_t field14;       // 0x14
    std::uint8_t unk18[0x40];    // 0x18
    std::uint32_t inheritFlags;  // 0x58
};

class Template2bbfe0
{
public:
    std::uint32_t GetValue() const;
};

class Obj2bbfe0
{
public:
    std::uint32_t Function2bbfe0() const;

    std::uint8_t unk00[0x40];          // 0x00
    std::uint8_t cellFlags;            // 0x40
    std::uint8_t unk41[0x27];          // 0x41
    InteriorData2bbfe0* interiorData;  // 0x68
    std::uint8_t unk70[0xC8];          // 0x70
    Template2bbfe0* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bbfe0, field14) == 0x14, "field14 offset");
static_assert(offsetof(InteriorData2bbfe0, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bbfe0, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bbfe0, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bbfe0, lightingTemplate) == 0x138, "lightingTemplate offset");
