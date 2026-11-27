// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e13b0: STANDIN GUESS(low)
// Unk6e13b0::Unk6e13b0: GUESS(low)
// Unk6e13b0::unk00, Unk6e13b0::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk6e13b0
{
public:
    Unk6e13b0(std::uint64_t first, std::uint64_t second);
    std::uint64_t unk00;
    std::uint64_t unk08;
};
static_assert(offsetof(Unk6e13b0, unk00) == 0, "field offset");
static_assert(offsetof(Unk6e13b0, unk08) == 8, "field offset");
