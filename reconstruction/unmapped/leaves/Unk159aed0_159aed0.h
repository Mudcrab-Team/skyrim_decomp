// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk159aed0, Unk159aed0::Function159aed0: GUESS(low)
// Unk159aed0::unk188: OBSERVED
// Unk159aed0::unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk159aed0
{
public:
    std::uint32_t Function159aed0();
    std::uint8_t unknown00[392];
    std::uint8_t unk188;
};

static_assert(offsetof(Unk159aed0, unk188) == 392, "field offset");
