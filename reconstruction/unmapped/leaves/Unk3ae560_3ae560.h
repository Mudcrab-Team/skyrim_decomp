// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk3ae560: STANDIN GUESS(low)
// Unk3ae560::Function3ae560: GUESS(low)
// Unk3ae560::unk00, Unk3ae560::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk3ae560
{
public:
    void Function3ae560();
    std::uint32_t unk00;
    std::uint8_t unknown04[4];
    std::uint64_t unk08;
};
static_assert(offsetof(Unk3ae560, unk00) == 0, "field offset");
static_assert(offsetof(Unk3ae560, unk08) == 8, "field offset");
