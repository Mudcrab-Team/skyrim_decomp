// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a5cf0, Unk4a5cf0::Function4a5cf0: GUESS(low)
// Unk4a5cf0::unk10: OBSERVED
// Unk4a5cf0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk4a5cf0
{
public:
    void Function4a5cf0(std::uint32_t value);
    std::uint8_t unknown00[16];
    std::uint32_t unk10;
};

static_assert(offsetof(Unk4a5cf0, unk10) == 16, "field offset");
