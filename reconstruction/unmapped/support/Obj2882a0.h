// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj2882a0, Obj2882a0::Function2882a0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj2882a0
{
public:
    void Function2882a0();

    std::uint8_t unk00[0x88];  // 0x00
    float f88;                 // 0x88
    float f8C;                 // 0x8C
    float f90;                 // 0x90
    float f94;                 // 0x94
    float f98;                 // 0x98
    float f9C;                 // 0x9C
    float fA0;                 // 0xA0
    float fA4;                 // 0xA4
    float fA8;                 // 0xA8
    float fAC;                 // 0xAC
    float fB0;                 // 0xB0
    float fB4;                 // 0xB4
    std::uint8_t unkB8[0x08];  // 0xB8
    std::uint32_t fieldC0;     // 0xC0
};

static_assert(offsetof(Obj2882a0, f88) == 0x88, "f88 offset");
static_assert(offsetof(Obj2882a0, fieldC0) == 0xC0, "fieldC0 offset");
