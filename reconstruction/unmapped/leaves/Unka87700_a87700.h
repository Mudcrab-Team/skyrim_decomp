// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unka87700: GUESS(low)
// Unka87700::Functiona87700: GUESS(low)
// Unka87700::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unka87700
{
public:
    bool Functiona87700();
    std::uint8_t unknown00[8];
    std::uint8_t unk08;
};
static_assert(offsetof(Unka87700, unk08) == 8, "field offset");
