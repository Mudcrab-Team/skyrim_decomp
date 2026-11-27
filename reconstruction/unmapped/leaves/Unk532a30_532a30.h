// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a30: STANDIN GUESS(low)
// Unk532a30::Function532a30: GUESS(low)
// Unk532a30::unknown0, Unk532a30::entries, ValueEntry532a30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueEntry532a30 { std::uint32_t value; std::uint32_t unknown04; };


class Unk532a30
{
public:
    std::uint32_t Function532a30(std::uint32_t index);
    std::uint8_t unknown0[8];
    ValueEntry532a30 entries[0];
};
static_assert(offsetof(Unk532a30, entries) == 8, "field offset");
