// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159b420, Unk159b420::Function159b420: GUESS(low)
// Unk159b420::unk08: OBSERVED
// Unk159b420::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159b420
{
public:
    void Function159b420(std::uint32_t value);
    std::uint8_t unknown00[8];
    std::uint32_t unk08;
};

static_assert(offsetof(Unk159b420, unk08) == 8, "field offset");
