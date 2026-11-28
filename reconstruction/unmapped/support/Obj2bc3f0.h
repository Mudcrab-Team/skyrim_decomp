// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2bc3f0::Function2bc3f0, treated as adapted: shaped like an inherited cell value getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:7093
// SPDX-License-Identifier: CC0-1.0
// InteriorData2bc3f0, Template2bc3f0, Obj2bc3f0, Obj2bc3f0::Function2bc3f0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct InteriorData2bc3f0
{
    std::uint8_t unk00[0x24];    // 0x00
    float field24;               // 0x24
    std::uint8_t unk28[0x30];    // 0x28
    std::uint32_t inheritFlags;  // 0x58
};

class Template2bc3f0
{
public:
    float GetValue() const;
};

class Obj2bc3f0
{
public:
    float Function2bc3f0() const;

    std::uint8_t unk00[0x40];          // 0x00
    std::uint8_t cellFlags;            // 0x40
    std::uint8_t unk41[0x27];          // 0x41
    InteriorData2bc3f0* interiorData;  // 0x68
    std::uint8_t unk70[0xC8];          // 0x70
    Template2bc3f0* lightingTemplate;  // 0x138
};

static_assert(offsetof(InteriorData2bc3f0, field24) == 0x24, "field24 offset");
static_assert(offsetof(InteriorData2bc3f0, inheritFlags) == 0x58, "inheritFlags offset");
static_assert(offsetof(Obj2bc3f0, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2bc3f0, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(Obj2bc3f0, lightingTemplate) == 0x138, "lightingTemplate offset");
