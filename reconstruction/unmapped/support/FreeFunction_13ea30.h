// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function13ea30: GUESS(low)
// Item13ea30: GUESS(low)
// Range13ea30: GUESS(low)
#pragma once

#include <cstdint>

struct Item13ea30
{
    virtual ~Item13ea30();
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Item13ea30) == 0xE8, "Item13ea30 size");

struct Range13ea30
{
    Item13ea30* first;
    Item13ea30* last;
};

void Function13ea30(Range13ea30* range);
