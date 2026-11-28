// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Vec213020, Unit213020, x, y, z, unk00, bounds, ContainsPoint213020: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Vec213020
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

struct Unit213020
{
    std::uint8_t unk00[0x0C];  // 00
    Vec213020 bounds;          // 0C

    bool ContainsPoint213020(const Vec213020& a_point) const;  // compared: 0x213020
};
static_assert(offsetof(Unit213020, bounds) == 0x0C, "Unit213020::bounds offset");
