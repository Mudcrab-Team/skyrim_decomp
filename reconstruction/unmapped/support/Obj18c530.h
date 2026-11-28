// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Handle18c530, Vec3_18c530, Base18c530, Obj18c530, gInvalidHandle18c530, gDefaultVec18c530: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::uint32_t gInvalidHandle18c530;

struct Vec3_18c530
{
    Vec3_18c530(const Vec3_18c530& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}

    float x;  // 00
    float y;  // 04
    float z;  // 08
};

extern Vec3_18c530 gDefaultVec18c530;

struct Handle18c530
{
    Handle18c530() : value(gInvalidHandle18c530) {}
    std::uint32_t value;  // 00
};

class Base18c530
{
public:
    Base18c530() : next(0) {}
    virtual ~Base18c530() {}

    void* next;  // 08
};

class Obj18c530 : public Base18c530
{
public:
    Obj18c530();  // compared: 0x18c530

    std::uint32_t unk10;   // 10
    Handle18c530 handle;   // 14
    void* unk18;           // 18
    void* unk20;           // 20
    Vec3_18c530 vec28;     // 28
    Vec3_18c530 vec34;     // 34
    std::uint32_t unk40;   // 40
    float unk44;           // 44
};
