// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk3ae540: STANDIN GUESS(low)
// Unk3ae540::Unk3ae540: GUESS(low)
// Unk3ae540::unk00, Unk3ae540::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk3ae540
{
public:
    Unk3ae540();
    std::uint32_t unk00;
    std::uint8_t unknown04[4];
    std::uint64_t unk08;
};
static_assert(offsetof(Unk3ae540, unk00) == 0, "field offset");
static_assert(offsetof(Unk3ae540, unk08) == 8, "field offset");
