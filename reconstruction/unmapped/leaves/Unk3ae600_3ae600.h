// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk3ae600: STANDIN GUESS(low)
// Unk3ae600::Function3ae600: GUESS(low)
// Unk3ae600::unk00, Unk3ae600::unknown4, Unk3ae600::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk3ae600
{
public:
    void Function3ae600(void* value);
    std::uint32_t unk00;
    std::uint8_t unknown4[4];
    void* unk08;
};
static_assert(offsetof(Unk3ae600, unk00) == 0, "field offset");
static_assert(offsetof(Unk3ae600, unk08) == 8, "field offset");
