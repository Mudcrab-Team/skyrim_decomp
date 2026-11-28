// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20d2d0, data, Length, IsEmpty20d2d0, g_prefix20d2d0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const char g_prefix20d2d0[];

struct Unit20d2d0
{
    const char* data;  // 00

    std::uint32_t Length() const;
    bool IsEmpty20d2d0() const;  // compared: 0x20d2d0
};
static_assert(offsetof(Unit20d2d0, data) == 0x00, "Unit20d2d0::data offset");
