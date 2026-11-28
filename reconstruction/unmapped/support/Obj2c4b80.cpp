// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Cookbook: 0x2c4b80 16
// Adapted bodies: Obj2c4b80::Function2c4b80, treated as adapted: shaped like TESObjectCELL::IsPointInCell in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:5699
// SPDX-License-Identifier: CC0-1.0
// 0x2c4b80 Obj2c4b80::Function2c4b80
#include "Obj2c4b80.h"

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value (cookbook rule 16).
    bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 0x1u) != 0;
    }

    std::int32_t FloorCoord(float a_value)
    {
        float asFloat = static_cast<float>(static_cast<std::int32_t>(a_value));
        float floored = (a_value - asFloat >= 0.0f) ? asFloat : (asFloat - 1.0f);
        return static_cast<std::int32_t>(floored);
    }
}

// Tests whether a 2D world position falls within an exterior cell's grid coordinates.
bool Obj2c4b80::Function2c4b80(const Point2D2c4b80& a_pos) const
{
    if ((cellFlags & 0x1u) != 0) {
        return false;
    }
    if (TestBit(formFlags, 13u)) {
        return true;
    }
    std::int32_t cellX;
    std::int32_t cellY;
    if (cellCoords) {
        cellX = cellCoords->x;
        cellY = cellCoords->y;
    } else {
        cellX = 0;
        cellY = 0;
    }
    if ((FloorCoord(a_pos.x) >> 12) != cellX) {
        return false;
    }
    if ((FloorCoord(a_pos.y) >> 12) != cellY) {
        return false;
    }
    return true;
}
