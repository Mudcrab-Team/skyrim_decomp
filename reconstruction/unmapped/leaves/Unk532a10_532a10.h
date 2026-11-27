// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk532a10: STANDIN GUESS(low)
// Unk532a10::Function532a10: GUESS(low)
// Unk532a10::unknown0, Unk532a10::entries, ValueEntry532a10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueEntry532a10 { std::uint64_t value; };


class Unk532a10
{
public:
    std::uint64_t Function532a10(std::uint32_t index);
    std::uint8_t unknown0[8];
    ValueEntry532a10 entries[0];
};
static_assert(offsetof(Unk532a10, entries) == 8, "field offset");
