// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159b3e0, Unk159b3e0::Function159b3e0: GUESS(low)
// Unk159b3e0::unk0c: OBSERVED
// Unk159b3e0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159b3e0
{
public:
    std::uint16_t Function159b3e0();
    std::uint8_t unknown00[12];
    std::uint16_t unk0c;
};

static_assert(offsetof(Unk159b3e0, unk0c) == 12, "field offset");
