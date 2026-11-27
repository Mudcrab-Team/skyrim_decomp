// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk8daed0, Unk8daed0::Function8daed0: GUESS(low)
// Unk8daed0::unk00: OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>

class Unk8daed0
{
public:
    Unk8daed0* Function8daed0();
    std::uint64_t unk00;
};

static_assert(offsetof(Unk8daed0, unk00) == 0, "field offset");
