// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Item13b3e0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

struct Item13b3e0
{
    std::uint8_t unk00[0xE8];
};

static_assert(sizeof(Item13b3e0) == 0xE8, "Item13b3e0 size");

