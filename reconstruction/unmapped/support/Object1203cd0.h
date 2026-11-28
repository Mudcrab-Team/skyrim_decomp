// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Vec3_1203cd0, Base1203cd0, Object1203cd0, x, y, z, unk00, flag2B, ptr30, position, owner, pos: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Vec3_1203cd0
{
    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08
};

struct Base1203cd0
{
    std::uint8_t unk00[0x2B];  // 0x00
    bool flag2B;               // 0x2B

    explicit Base1203cd0(void* owner);
};
static_assert(offsetof(Base1203cd0, flag2B) == 0x2B, "flag2B offset");

struct Object1203cd0 : Base1203cd0
{
    void* ptr30;            // 0x30
    Vec3_1203cd0 position;  // 0x38

    Object1203cd0(void* owner, const Vec3_1203cd0* pos);
};
static_assert(offsetof(Object1203cd0, ptr30) == 0x30, "ptr30 offset");
static_assert(offsetof(Object1203cd0, position) == 0x38, "position offset");
