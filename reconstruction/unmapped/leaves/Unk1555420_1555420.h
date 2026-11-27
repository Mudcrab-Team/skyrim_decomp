// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1555420, Unk1555420::Function1555420: GUESS(low)
// Unk1555420::unk28: OBSERVED
// Unk1555420::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1555420
{
public:
    void Function1555420(std::uint64_t value);
    std::uint8_t unknown00[40];
    std::uint64_t unk28;
};

static_assert(offsetof(Unk1555420, unk28) == 40, "field offset");
