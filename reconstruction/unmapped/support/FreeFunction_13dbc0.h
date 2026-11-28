// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function13dbc0: GUESS(low)
// Item13dbc0: GUESS(low)
#pragma once

#include <cstdint>

struct Item13dbc0
{
    virtual ~Item13dbc0();
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Item13dbc0) == 0xE8, "Item13dbc0 size");

void Function13dbc0(Item13dbc0* first, Item13dbc0* last);
