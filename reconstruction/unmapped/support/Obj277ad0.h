// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj277ad0, Obj277ad0::Function277ad0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj277ad0
{
public:
    float Function277ad0() const;

    std::uint8_t unk00[0x20];  // 0x00
    std::int16_t maxX;         // 0x20
    std::int16_t maxY;         // 0x22
    std::int16_t maxZ;         // 0x24
    std::int16_t minX;         // 0x26
    std::int16_t minY;         // 0x28
    std::int16_t minZ;         // 0x2A
};

static_assert(offsetof(Obj277ad0, maxX) == 0x20, "maxX offset");
static_assert(offsetof(Obj277ad0, minX) == 0x26, "minX offset");
