// Source exposure: binary-analysis.
// Code origin: original member reset reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk5ece70, Unk5ece70::Function5ece70, Unk5ece70::unk40: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk5ece70
{
public:
    void Function5ece70();
    std::uint8_t unknown00[64];
    std::uint64_t unk40;
};
static_assert(offsetof(Unk5ece70, unk40) == 64, "field offset");
