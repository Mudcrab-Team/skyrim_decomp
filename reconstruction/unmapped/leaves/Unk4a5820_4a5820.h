// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5820: STANDIN GUESS(low)
// Unk4a5820::Unk4a5820: GUESS(low)
// Unk4a5820::unk00, Unk4a5820::unk08, Unk4a5820::unk10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk4a5820
{
public:
    Unk4a5820();
    std::uint8_t unk00;
    std::uint8_t unknown01[7];
    std::uint32_t unk08;
    std::uint8_t unknown0c[4];
    std::uint32_t unk10;
};
static_assert(offsetof(Unk4a5820, unk00) == 0, "field offset");
static_assert(offsetof(Unk4a5820, unk08) == 8, "field offset");
static_assert(offsetof(Unk4a5820, unk10) == 16, "field offset");
