// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// AllocEngine_1194080, Function1194080, unk00, shift, unk30, granuleCount, unk658, footprint, freeSpace, engine: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct AllocEngine_1194080
{
    std::uint8_t unk00[0x28];    // 0x000
    std::size_t shift;           // 0x028
    std::uint8_t unk30[0x620];   // 0x030
    std::size_t granuleCount;    // 0x650
    std::uint8_t unk658[0xC0];   // 0x658
    std::size_t footprint;       // 0x718
    std::size_t freeSpace;       // 0x720
};
static_assert(offsetof(AllocEngine_1194080, shift) == 0x28, "shift offset");
static_assert(offsetof(AllocEngine_1194080, granuleCount) == 0x650, "granuleCount offset");
static_assert(offsetof(AllocEngine_1194080, footprint) == 0x718, "footprint offset");
static_assert(offsetof(AllocEngine_1194080, freeSpace) == 0x720, "freeSpace offset");

std::size_t Function1194080(const AllocEngine_1194080* engine);
