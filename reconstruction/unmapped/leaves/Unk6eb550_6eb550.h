// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk6eb550, Unk6eb550::Function6eb550: GUESS(low)
// Unk6eb550::unkb8: OBSERVED
// Unk6eb550::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6eb550
{
public:
    std::uint64_t* Function6eb550();
    std::uint8_t unknown00[184];
    std::uint64_t unkb8;
};

static_assert(offsetof(Unk6eb550, unkb8) == 184, "field offset");
