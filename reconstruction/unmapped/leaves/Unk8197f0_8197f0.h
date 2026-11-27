// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk8197f0: GUESS(low)
// Unk8197f0::Function8197f0: GUESS(low)
// Unk8197f0::unk30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk8197f0
{
public:
    bool Function8197f0();
    std::uint8_t unknown00[48];
    std::uint32_t unk30;
};
static_assert(offsetof(Unk8197f0, unk30) == 48, "field offset");
