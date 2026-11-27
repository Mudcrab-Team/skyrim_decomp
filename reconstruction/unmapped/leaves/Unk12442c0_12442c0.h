// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk12442c0: GUESS(low)
// Unk12442c0::Function12442c0: GUESS(low)
// Unk12442c0::unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk12442c0
{
public:
    bool Function12442c0();
    std::uint32_t unk00;
};
static_assert(offsetof(Unk12442c0, unk00) == 0, "field offset");
