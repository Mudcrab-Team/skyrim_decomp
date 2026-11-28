// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Vec213340, Unit213340, x, y, z, unk00, bounds, ContainsPoint213340: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Vec213340
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct Unit213340
{
    std::uint8_t unk00[0x0C];  // 00
    Vec213340 bounds;          // 0C

    bool ContainsPoint213340(const Vec213340& a_point) const;  // compared: 0x213340
};
static_assert(offsetof(Unit213340, bounds) == 0x0C, "Unit213340::bounds offset");
