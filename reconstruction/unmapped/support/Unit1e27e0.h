// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1e27e0, Equals1e27e0, data, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Unit1e27e0
{
    void** data;          // 00
    std::uint32_t count;  // 08

    bool Equals1e27e0(const Unit1e27e0& a_other) const;  // compared: 0x1e27e0
};
static_assert(offsetof(Unit1e27e0, count) == 0x08, "Unit1e27e0::count offset");
