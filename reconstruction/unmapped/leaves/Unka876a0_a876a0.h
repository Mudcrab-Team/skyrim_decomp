// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unka876a0: GUESS(low)
// Unka876a0::Functiona876a0: GUESS(low)
// Unka876a0::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unka876a0
{
public:
    bool Functiona876a0();
    std::uint8_t unknown00[8];
    std::uint8_t unk08;
};
static_assert(offsetof(Unka876a0, unk08) == 8, "field offset");
