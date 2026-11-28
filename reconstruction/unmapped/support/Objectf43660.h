// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Bounds_f43660, Objectf43660, minX, minY, minZ, maxX, maxY, maxZ, f08, f0c, invF0c, f14, u18, u1c, f20, bounds, arg1, arg2, arg3, arg4: GUESS(low)
#pragma once

#include <cfloat>
#include <cstddef>
#include <cstdint>

struct Bounds_f43660
{
    float minX;  // 0x00
    float minY;  // 0x04
    float minZ;  // 0x08
    float maxX;  // 0x0C
    float maxY;  // 0x10
    float maxZ;  // 0x14

    Bounds_f43660()
        : minX(FLT_MAX), minY(FLT_MAX), minZ(FLT_MAX), maxX(FLT_MAX), maxY(FLT_MAX), maxZ(FLT_MAX)
    {
    }
};

class Objectf43660
{
public:
    float f08;             // 0x08
    float f0c;             // 0x0C
    float invF0c;          // 0x10
    float f14;             // 0x14
    std::uint32_t u18;     // 0x18
    std::uint32_t u1c;     // 0x1C
    float f20;             // 0x20
    Bounds_f43660 bounds;  // 0x24

    Objectf43660(float arg1, float arg2, float arg3, std::uint32_t arg4);
    virtual ~Objectf43660();
};
static_assert(offsetof(Objectf43660, f08) == 0x08, "f08 offset");
static_assert(offsetof(Objectf43660, f0c) == 0x0C, "f0c offset");
static_assert(offsetof(Objectf43660, invF0c) == 0x10, "invF0c offset");
static_assert(offsetof(Objectf43660, f14) == 0x14, "f14 offset");
static_assert(offsetof(Objectf43660, u18) == 0x18, "u18 offset");
static_assert(offsetof(Objectf43660, u1c) == 0x1C, "u1c offset");
static_assert(offsetof(Objectf43660, f20) == 0x20, "f20 offset");
static_assert(offsetof(Objectf43660, bounds) == 0x24, "bounds offset");
