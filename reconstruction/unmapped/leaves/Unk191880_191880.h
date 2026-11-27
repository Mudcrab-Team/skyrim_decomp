// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk191880, Unk191880::Function191880: GUESS(low)
// Unk191880::unk04: OBSERVED
// Unk191880::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk191880
{
public:
    std::uint8_t* Function191880();
    std::uint8_t unknown00[4];
    std::uint8_t unk04;
};

static_assert(offsetof(Unk191880, unk04) == 4, "field offset");
