// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk5ec790: STANDIN GUESS(low)
// Unk5ec790::Function5ec790: GUESS(low)
// Unk5ec790::unknown0, Unk5ec790::value, Link5ec790: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Link5ec790 { void* link; };


class Unk5ec790
{
public:
    void* Function5ec790();
    std::uint8_t unknown0[24];
    Link5ec790* value;
};
static_assert(offsetof(Unk5ec790, value) == 24, "field offset");
