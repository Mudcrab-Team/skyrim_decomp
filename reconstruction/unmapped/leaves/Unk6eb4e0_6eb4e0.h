// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk6eb4e0, Unk6eb4e0::Function6eb4e0: GUESS(low)
// Unk6eb4e0::unk13a: OBSERVED
// Unk6eb4e0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6eb4e0
{
public:
    std::uint8_t Function6eb4e0();
    std::uint8_t unknown00[314];
    std::uint8_t unk13a;
};

static_assert(offsetof(Unk6eb4e0, unk13a) == 314, "field offset");
