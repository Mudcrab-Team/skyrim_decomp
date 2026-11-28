// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Vec3_11b65c0, Object11b65c0, x, y, z, position, ptr10, ptr18, ptr20, flags28: GUESS(low)
#pragma once

#include <cfloat>
#include <cstddef>
#include <cstdint>

struct Vec3_11b65c0
{
    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08

    Vec3_11b65c0() : x(FLT_MAX), y(FLT_MAX), z(FLT_MAX) {}
};

struct Object11b65c0
{
    Vec3_11b65c0 position;  // 0x00
    void* ptr10;            // 0x10
    void* ptr18;            // 0x18
    void* ptr20;            // 0x20
    std::uint32_t flags28;  // 0x28

    Object11b65c0();
};
static_assert(offsetof(Object11b65c0, ptr10) == 0x10, "ptr10 offset");
static_assert(offsetof(Object11b65c0, flags28) == 0x28, "flags28 offset");
