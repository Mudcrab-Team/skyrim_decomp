// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk222d70, Unk222d70::Function222d70: GUESS(low)
// Unk222d70::unk02: OBSERVED
// Unk222d70::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk222d70
{
public:
    std::uint32_t Function222d70();
    std::uint8_t unknown00[2];
    std::uint16_t unk02;
};

static_assert(offsetof(Unk222d70, unk02) == 2, "field offset");
