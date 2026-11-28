// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Vec3_24b0d0, Obj24b0d0, flag, ptr, position, g_defaultPosition: GUESS(low)
#pragma once

#include <cstdint>

struct Vec3_24b0d0
{
    Vec3_24b0d0() : x(0.0f), y(0.0f), z(0.0f) {}

    float x;  // 00
    float y;  // 04
    float z;  // 08
};

extern Vec3_24b0d0 g_defaultPosition;

class Obj24b0d0
{
public:
    Obj24b0d0();

    std::uint8_t flag;     // 00
    void* ptr;             // 08
    Vec3_24b0d0 position;  // 10
};
