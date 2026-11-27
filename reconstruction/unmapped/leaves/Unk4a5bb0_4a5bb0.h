// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5bb0: STANDIN GUESS(low)
// Unk4a5bb0::Function4a5bb0: GUESS(low)
// Unk4a5bb0::tag, Unk4a5bb0::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk4a5bb0
{
public:
    std::uint64_t Function4a5bb0();
    std::uint8_t tag;
    std::uint8_t unknown1[7];
    std::uint64_t value;
};
static_assert(offsetof(Unk4a5bb0, tag) == 0, "field offset");
static_assert(offsetof(Unk4a5bb0, value) == 8, "field offset");
