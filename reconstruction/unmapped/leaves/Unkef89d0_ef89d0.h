// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unkef89d0: STANDIN GUESS(low)
// Unkef89d0::Unkef89d0: GUESS(low)
// Unkef89d0::unk18, Unkef89d0::unk00, Unkef89d0::unk08, Unkef89d0::unk10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unkef89d0
{
public:
    Unkef89d0(std::uint8_t first);
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint8_t unk18;
};
static_assert(offsetof(Unkef89d0, unk18) == 24, "field offset");
static_assert(offsetof(Unkef89d0, unk00) == 0, "field offset");
static_assert(offsetof(Unkef89d0, unk08) == 8, "field offset");
static_assert(offsetof(Unkef89d0, unk10) == 16, "field offset");
