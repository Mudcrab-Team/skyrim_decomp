// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a20: STANDIN GUESS(low)
// Unk532a20::Function532a20: GUESS(low)
// Unk532a20::unknown0, Unk532a20::entries, ValueEntry532a20: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueEntry532a20 { std::uint64_t value; };


class Unk532a20
{
public:
    std::uint64_t Function532a20(std::uint32_t index);
    std::uint8_t unknown0[8];
    ValueEntry532a20 entries[0];
};
static_assert(offsetof(Unk532a20, entries) == 8, "field offset");
