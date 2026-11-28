// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Vec3_24b470, Item24b470, Obj24b470, IsDifferent, count, items, position: GUESS(low)
#pragma once

#include <cstdint>

struct Vec3_24b470
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct Item24b470
{
    std::uint32_t unk00;  // 00
    std::uint32_t unk04;  // 04
    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint32_t unk10;  // 10
    std::uint32_t unk14;  // 14
    std::uint32_t unk18;  // 18
};

class Obj24b470
{
public:
    bool IsDifferent(const Obj24b470* other) const;

    std::uint8_t count;    // 00
    Item24b470* items;     // 08
    Vec3_24b470 position;  // 10
};
