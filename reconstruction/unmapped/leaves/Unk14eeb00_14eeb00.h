// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk14eeb00, Unk14eeb00::Function14eeb00: GUESS(low)
// Unk14eeb00::unkb0: OBSERVED
// Unk14eeb00::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk14eeb00
{
public:
    void Function14eeb00(std::uint64_t value);
    std::uint8_t unknown00[176];
    std::uint64_t unkb0;
};

static_assert(offsetof(Unk14eeb00, unkb0) == 176, "field offset");
