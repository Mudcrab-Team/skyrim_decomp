// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5c90: STANDIN GUESS(low)
// Unk4a5c90::Function4a5c90: GUESS(low)
// Unk4a5c90::tag, Unk4a5c90::storedValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk4a5c90
{
public:
    void Function4a5c90(const std::uint32_t& value);
    std::uint8_t tag;
    std::uint8_t unknown1[7];
    std::uint32_t storedValue;
};
static_assert(offsetof(Unk4a5c90, tag) == 0, "field offset");
static_assert(offsetof(Unk4a5c90, storedValue) == 8, "field offset");
