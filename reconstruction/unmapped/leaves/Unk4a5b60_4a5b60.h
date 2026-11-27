// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5b60: STANDIN GUESS(low)
// Unk4a5b60::Function4a5b60: GUESS(low)
// Unk4a5b60::tag, Unk4a5b60::unknown1, Unk4a5b60::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk4a5b60
{
public:
    std::uint32_t Function4a5b60();
    std::uint8_t tag;
    std::uint8_t unknown1[7];
    std::uint32_t value;
};
static_assert(offsetof(Unk4a5b60, tag) == 0, "field offset");
static_assert(offsetof(Unk4a5b60, value) == 8, "field offset");
