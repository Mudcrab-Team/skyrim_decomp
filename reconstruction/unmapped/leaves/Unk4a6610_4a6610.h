// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a6610: STANDIN GUESS(low)
// Unk4a6610::Function4a6610: GUESS(low)
// Unk4a6610::tag, Unk4a6610::value, gFallback4a6610: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


extern std::uint32_t gFallback4a6610;
class Unk4a6610
{
public:
    std::uint32_t* Function4a6610(std::uint32_t* output);
    std::uint8_t tag;
    std::uint8_t unknown1[7];
    std::uint32_t value;
};
static_assert(offsetof(Unk4a6610, tag) == 0, "field offset");
static_assert(offsetof(Unk4a6610, value) == 8, "field offset");
