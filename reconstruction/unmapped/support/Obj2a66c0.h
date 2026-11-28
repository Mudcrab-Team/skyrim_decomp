// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj2a66c0, Obj2a66c0::Function2a66c0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj2a66c0
{
public:
    void Function2a66c0();

    std::uint8_t unk00[0x20];  // 0x00
    float f20;                 // 0x20
    float f24;                 // 0x24
    float f28;                 // 0x28
    float f2C;                 // 0x2C
    float f30;                 // 0x30
    float f34;                 // 0x34
    float f38;                 // 0x38
    float f3C;                 // 0x3C
    float f40;                 // 0x40
    float f44;                 // 0x44
    float f48;                 // 0x48
    float f4C;                 // 0x4C
    float tail[7];             // 0x50
};

static_assert(offsetof(Obj2a66c0, f20) == 0x20, "f20 offset");
static_assert(offsetof(Obj2a66c0, tail) == 0x50, "tail offset");
