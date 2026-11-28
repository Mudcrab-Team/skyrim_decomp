// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing using standard library headers
// SPDX-License-Identifier: CC0-1.0
// Element13c6e0, Function13c6e0, unk00, items, unk40, first, last: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Element13c6e0
{
    std::uint64_t unk00[5];            // 0x00
    std::vector<std::uint64_t> items;  // 0x28
    std::uint64_t unk40[3];            // 0x40
};
static_assert(sizeof(Element13c6e0) == 0x58, "Element13c6e0 size");

void Function13c6e0(Element13c6e0* first, Element13c6e0* last);
