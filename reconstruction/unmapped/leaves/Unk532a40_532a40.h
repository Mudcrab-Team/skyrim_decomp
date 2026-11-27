// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a40: STANDIN GUESS(low)
// Unk532a40::Function532a40: GUESS(low)
// Unk532a40::entries: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk532a40
{
public:
    std::uint64_t Function532a40(std::uint32_t index);
    std::uint8_t unknown0[8];
    std::uint64_t entries[0];
};
static_assert(offsetof(Unk532a40, entries) == 8, "field offset");
