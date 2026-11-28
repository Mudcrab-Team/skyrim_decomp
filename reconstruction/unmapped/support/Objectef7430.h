// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Vec3_ef7430, Objectef7430, g_defaultPos_ef7430, x, y, z, position, unk0C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Vec3_ef7430
{
    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08

    Vec3_ef7430() : x(0.0f), y(0.0f), z(0.0f) {}
};

extern Vec3_ef7430 g_defaultPos_ef7430;

struct Objectef7430
{
    Vec3_ef7430 position;  // 0x00
    std::uint32_t unk0C;   // 0x0C

    Objectef7430();
};
static_assert(offsetof(Objectef7430, unk0C) == 0x0C, "unk0C offset");
