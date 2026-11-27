// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk7c2fe0: STANDIN GUESS(low)
// Unk7c2fe0::Function7c2fe0: GUESS(low)
// Unk7c2fe0::count: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk7c2fe0
{
public:
    void Function7c2fe0(std::uint32_t value);
    std::uint8_t unknown0[228];
    std::uint32_t count;
};
static_assert(offsetof(Unk7c2fe0, count) == 228, "field offset");
