// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Item13b370: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Item13b370
{
    virtual ~Item13b370();
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Item13b370) == 0xE8, "Item13b370 size");

