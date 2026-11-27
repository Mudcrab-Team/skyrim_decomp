// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unkcdd660, Unkcdd660::Functioncdd660: GUESS(low)
// Unkcdd660::unk440: OBSERVED
// Unkcdd660::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unkcdd660
{
public:
    void Functioncdd660(std::uint64_t value);
    std::uint8_t unknown00[1088];
    std::uint64_t unk440;
};

static_assert(offsetof(Unkcdd660, unk440) == 1088, "field offset");
