// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk44b560: STANDIN GUESS(low)
// Unk44b560::Unk44b560: GUESS(low)
// Unk44b560::unk00, Unk44b560::unk08, Unk44b560::unk10, Unk44b560::unk12: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk44b560
{
public:
    Unk44b560();
    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint16_t unk10;
    std::uint8_t unk12;
};
static_assert(offsetof(Unk44b560, unk00) == 0, "field offset");
static_assert(offsetof(Unk44b560, unk08) == 8, "field offset");
static_assert(offsetof(Unk44b560, unk10) == 16, "field offset");
static_assert(offsetof(Unk44b560, unk12) == 18, "field offset");
