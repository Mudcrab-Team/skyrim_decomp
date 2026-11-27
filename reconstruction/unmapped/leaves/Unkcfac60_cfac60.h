// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkcfac60, Unkcfac60::Functioncfac60: GUESS(low)
// Unkcfac60::unk04: OBSERVED
// Unkcfac60::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unkcfac60
{
public:
    std::uint16_t Functioncfac60();
    std::uint8_t unknown00[4];
    std::uint16_t unk04;
};

static_assert(offsetof(Unkcfac60, unk04) == 4, "field offset");
