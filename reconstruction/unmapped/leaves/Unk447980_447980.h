// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk447980: GUESS(low)
// Unk447980::Function447980: GUESS(low)
// Unk447980::unk1c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk447980
{
public:
    void Function447980();
    std::uint8_t unknown00[28];
    std::uint32_t unk1c;
};
static_assert(offsetof(Unk447980, unk1c) == 28, "field offset");
