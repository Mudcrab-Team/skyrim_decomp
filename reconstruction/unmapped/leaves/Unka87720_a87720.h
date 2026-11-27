// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unka87720: GUESS(low)
// Unka87720::Functiona87720: GUESS(low)
// Unka87720::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unka87720
{
public:
    bool Functiona87720();
    std::uint8_t unknown00[8];
    std::uint8_t unk08;
};
static_assert(offsetof(Unka87720, unk08) == 8, "field offset");
