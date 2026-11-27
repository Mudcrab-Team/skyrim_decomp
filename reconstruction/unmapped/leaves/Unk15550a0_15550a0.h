// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15550a0, Unk15550a0::Function15550a0: GUESS(low)
// Unk15550a0::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk15550a0
{
public:
    std::uint64_t Function15550a0();
    std::uint64_t unk00;
};

static_assert(offsetof(Unk15550a0, unk00) == 0, "field offset");
