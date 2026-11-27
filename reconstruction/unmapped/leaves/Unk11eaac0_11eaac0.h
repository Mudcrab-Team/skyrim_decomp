// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk11eaac0, Unk11eaac0::Function11eaac0: GUESS(low)
// Unk11eaac0::unk28: OBSERVED
// Unk11eaac0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk11eaac0
{
public:
    void Function11eaac0(std::uint64_t value);
    std::uint8_t unknown00[40];
    std::uint64_t unk28;
};

static_assert(offsetof(Unk11eaac0, unk28) == 40, "field offset");
