// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5b40: STANDIN GUESS(low)
// Unk4a5b40::Function4a5b40: GUESS(low)
// Unk4a5b40::tag, Unk4a5b40::unknown1, Unk4a5b40::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk4a5b40
{
public:
    std::uint32_t Function4a5b40();
    std::uint8_t tag;
    std::uint8_t unknown1[7];
    std::uint32_t value;
};
static_assert(offsetof(Unk4a5b40, tag) == 0, "field offset");
static_assert(offsetof(Unk4a5b40, value) == 8, "field offset");
