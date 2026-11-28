// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit211f40, first, second, ShiftRange211f40: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Unit211f40
{
    void* first[63];   // 000
    void* second[63];  // 1F8

    void ShiftRange211f40(std::uint32_t a_start, std::uint32_t a_end);  // compared: 0x211f40
};
static_assert(offsetof(Unit211f40, second) == 0x1F8, "Unit211f40::second offset");
