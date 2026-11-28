// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Elem1398e0: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Elem1398e0
{
    virtual ~Elem1398e0() {}
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Elem1398e0) == 0xE8, "Elem1398e0 size mismatch");

