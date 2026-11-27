// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1555130, Unk1555130::Function1555130: GUESS(low)
// Unk1555130::unk14: OBSERVED
// Unk1555130::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1555130
{
public:
    void Function1555130(std::uint32_t value);
    std::uint8_t unknown00[20];
    std::uint32_t unk14;
};

static_assert(offsetof(Unk1555130, unk14) == 20, "field offset");
