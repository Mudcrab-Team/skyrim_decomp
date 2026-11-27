// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159b4f0, Unk159b4f0::Function159b4f0: GUESS(low)
// Unk159b4f0::unk20: OBSERVED
// Unk159b4f0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159b4f0
{
public:
    std::uint16_t Function159b4f0();
    std::uint8_t unknown00[32];
    std::uint16_t unk20;
};

static_assert(offsetof(Unk159b4f0, unk20) == 32, "field offset");
