// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk6eb4f0, Unk6eb4f0::Function6eb4f0: GUESS(low)
// Unk6eb4f0::unk13a: OBSERVED
// Unk6eb4f0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6eb4f0
{
public:
    void Function6eb4f0(std::uint8_t value);
    std::uint8_t unknown00[314];
    std::uint8_t unk13a;
};

static_assert(offsetof(Unk6eb4f0, unk13a) == 314, "field offset");
