// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk44d790: STANDIN GUESS(low)
// Unk44d790::Unk44d790: GUESS(low)
// Unk44d790::unk00, Unk44d790::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk44d790
{
public:
    Unk44d790(std::uint64_t first, std::uint64_t second);
    std::uint64_t unk00;
    std::uint64_t unk08;
};
static_assert(offsetof(Unk44d790, unk00) == 0, "field offset");
static_assert(offsetof(Unk44d790, unk08) == 8, "field offset");
