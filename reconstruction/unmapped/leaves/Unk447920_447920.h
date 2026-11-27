// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk447920: GUESS(low)
// Unk447920::Function447920: GUESS(low)
// Unk447920::unk04: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk447920
{
public:
    void Function447920();
    std::uint8_t unknown00[4];
    std::uint32_t unk04;
};
static_assert(offsetof(Unk447920, unk04) == 4, "field offset");
