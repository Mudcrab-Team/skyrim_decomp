// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159b3f0, Unk159b3f0::Function159b3f0: GUESS(low)
// Unk159b3f0::unk0e: OBSERVED
// Unk159b3f0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159b3f0
{
public:
    std::uint16_t Function159b3f0();
    std::uint8_t unknown00[14];
    std::uint16_t unk0e;
};

static_assert(offsetof(Unk159b3f0, unk0e) == 14, "field offset");
