// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2c4b80::Function2c4b80, treated as adapted: shaped like TESObjectCELL::IsPointInCell in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:5699
// SPDX-License-Identifier: CC0-1.0
// Point2D2c4b80, CellCoords2c4b80, Obj2c4b80, Obj2c4b80::Function2c4b80: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Point2D2c4b80
{
    float x;  // 0x00
    float y;  // 0x04
};

struct CellCoords2c4b80
{
    std::int32_t x;  // 0x00
    std::int32_t y;  // 0x04
};

class Obj2c4b80
{
public:
    bool Function2c4b80(const Point2D2c4b80& a_pos) const;

    std::uint8_t unk00[0x10];           // 0x00
    std::uint32_t formFlags;            // 0x10
    std::uint8_t unk14[0x2C];           // 0x14
    std::uint16_t cellFlags;            // 0x40
    std::uint8_t unk42[0x26];           // 0x42
    const CellCoords2c4b80* cellCoords; // 0x68
};

static_assert(offsetof(Obj2c4b80, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(Obj2c4b80, cellCoords) == 0x68, "cellCoords offset");
