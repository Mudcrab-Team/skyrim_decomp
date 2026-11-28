// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2c45b0::Function2c45b0, treated as adapted: shaped like TESObjectCELL::GetDistanceFromPoint in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:14642
// SPDX-License-Identifier: CC0-1.0
// Point2D2c45b0, CellData2c45b0, Obj2c45b0, Obj2c45b0::Function2c45b0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Point2D2c45b0
{
    float x;  // 0x00
    float y;  // 0x04
};

struct CellData2c45b0
{
    std::uint8_t unk00[0x18];  // 0x00
    float minX;                // 0x18
    float minY;                // 0x1C
};

class Obj2c45b0
{
public:
    float Function2c45b0(const Point2D2c45b0& a_pos) const;

    std::uint8_t unk00[0x40];        // 0x00
    std::uint16_t cellFlags;         // 0x40
    std::uint8_t unk42[0x26];        // 0x42
    const CellData2c45b0* cellData;  // 0x68
};

static_assert(offsetof(CellData2c45b0, minX) == 0x18, "minX offset");
static_assert(offsetof(Obj2c45b0, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2c45b0, cellData) == 0x68, "cellData offset");
