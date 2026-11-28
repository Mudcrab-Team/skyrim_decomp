// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Point3D2b2960, Cell2b2960, LandData2b2960, Obj2b2960: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Point3D2b2960
{
    Point3D2b2960() : x(0.0f), y(0.0f), z(0.0f) {}

    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08
};

struct Cell2b2960
{
    std::int32_t GetCoordX() const;
    std::int32_t GetCoordY() const;
};

struct LandData2b2960
{
    std::uint8_t unk00[0x49B8];  // 0x0000
    std::int32_t coordX;         // 0x49B8
    std::int32_t coordY;         // 0x49BC
    float baseHeight;            // 0x49C0
};

class Obj2b2960
{
public:
    Point3D2b2960 Function2b2960() const;

    std::uint8_t unk00[0x30];      // 0x00
    const Cell2b2960* cell30;      // 0x30
    std::uint8_t unk38[0x08];      // 0x38
    const LandData2b2960* data40;  // 0x40
};

static_assert(sizeof(Point3D2b2960) == 0x0C, "Point3D2b2960 size");
static_assert(offsetof(LandData2b2960, coordX) == 0x49B8, "coordX offset");
static_assert(offsetof(LandData2b2960, baseHeight) == 0x49C0, "baseHeight offset");
static_assert(offsetof(Obj2b2960, cell30) == 0x30, "cell30 offset");
static_assert(offsetof(Obj2b2960, data40) == 0x40, "data40 offset");
