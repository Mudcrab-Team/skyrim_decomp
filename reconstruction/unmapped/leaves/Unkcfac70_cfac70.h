// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkcfac70, Unkcfac70::Functioncfac70: GUESS(low)
// Unkcfac70::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unkcfac70
{
public:
    std::uint32_t Functioncfac70();
    std::uint16_t unk00;
};

static_assert(offsetof(Unkcfac70, unk00) == 0, "field offset");
