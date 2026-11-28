// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation from standard headers, selected from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Elem13c980: GUESS(low)
// Func_13c980: GUESS(low)
#pragma once

#include <cstdint>

struct Elem13c980
{
    virtual ~Elem13c980() {}
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Elem13c980) == 0xE8, "Elem13c980 size mismatch");

struct Func_13c980
{
};
