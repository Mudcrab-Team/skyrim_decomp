// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit20dbd0, data, Length, GetStrippedLength20dbd0, g_prefix20dbd0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const char g_prefix20dbd0[];

struct Unit20dbd0
{
    const char* data;  // 00

    std::uint32_t Length() const;
    std::uint32_t GetStrippedLength20dbd0() const;  // compared: 0x20dbd0
};
static_assert(offsetof(Unit20dbd0, data) == 0x00, "Unit20dbd0::data offset");
