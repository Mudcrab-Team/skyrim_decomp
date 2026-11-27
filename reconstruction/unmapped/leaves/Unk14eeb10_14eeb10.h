// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk14eeb10, Unk14eeb10::Function14eeb10: GUESS(low)
// Unk14eeb10::unkb8: OBSERVED
// Unk14eeb10::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk14eeb10
{
public:
    void Function14eeb10(std::uint64_t value);
    std::uint8_t unknown00[184];
    std::uint64_t unkb8;
};

static_assert(offsetof(Unk14eeb10, unkb8) == 184, "field offset");
