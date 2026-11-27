// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk11d7bc0: STANDIN GUESS(low)
// Unk11d7bc0::Function11d7bc0: GUESS(low)
// Unk11d7bc0::unknown0, Unk11d7bc0::unk88, Unk11d7bc0::unk8c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk11d7bc0
{
public:
    void Function11d7bc0(std::uint32_t first, std::uint32_t second);
    std::uint8_t unknown0[136];
    std::uint32_t unk88;
    std::uint32_t unk8c;
};
static_assert(offsetof(Unk11d7bc0, unk88) == 136, "field offset");
static_assert(offsetof(Unk11d7bc0, unk8c) == 140, "field offset");
