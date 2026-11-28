// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function13c7a0: GUESS(low)
// Item13c7a0: GUESS(low)
#pragma once

#include <cstdint>

struct Item13c7a0
{
    virtual ~Item13c7a0();
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Item13c7a0) == 0xE8, "Item13c7a0 size");

void Function13c7a0(Item13c7a0* first, Item13c7a0* last);
