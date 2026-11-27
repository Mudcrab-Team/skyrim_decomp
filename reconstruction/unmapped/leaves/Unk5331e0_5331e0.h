// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk5331e0: STANDIN GUESS(low)
// Unk5331e0::Function5331e0: GUESS(low)
// Unk5331e0::values, ValueEntry5331e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValueEntry5331e0 { std::uint64_t values[5]; };

class Unk5331e0
{
public:
    ValueEntry5331e0* Function5331e0(std::uint32_t index);
    ValueEntry5331e0* values;
};
static_assert(offsetof(Unk5331e0, values) == 0, "field offset");
