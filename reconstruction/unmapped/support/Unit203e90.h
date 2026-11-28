// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit203e90, values, tail, scale: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Unit203e90
{
    std::uint32_t values[6];  // 00
    std::uint32_t tail;       // 18
    float scale;              // 1C

    Unit203e90();  // compared: 0x203e90
};
static_assert(offsetof(Unit203e90, tail) == 0x18, "Unit203e90::tail offset");
static_assert(offsetof(Unit203e90, scale) == 0x1C, "Unit203e90::scale offset");
