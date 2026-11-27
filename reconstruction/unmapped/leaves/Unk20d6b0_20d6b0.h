// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk20d6b0, Unk20d6b0::Function20d6b0: GUESS(low)
// Unk20d6b0::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk20d6b0
{
public:
    Unk20d6b0* Function20d6b0();
    std::uint32_t unk00;
};

static_assert(offsetof(Unk20d6b0, unk00) == 0, "field offset");
