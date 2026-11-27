// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk5329f0: STANDIN GUESS(low)
// Unk5329f0::Function5329f0: GUESS(low)
// Unk5329f0::unknown0, Unk5329f0::entries, ValueEntry5329f0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueEntry5329f0 { std::uint32_t value; std::uint32_t unknown04; };


class Unk5329f0
{
public:
    std::uint32_t* Function5329f0(std::uint32_t* output, std::uint32_t index);
    std::uint8_t unknown0[8];
    ValueEntry5329f0 entries[0];
};
static_assert(offsetof(Unk5329f0, entries) == 8, "field offset");
