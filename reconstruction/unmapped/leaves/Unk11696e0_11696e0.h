// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk11696e0: GUESS(low)
// Unk11696e0::Function11696e0: GUESS(low)
// Unk11696e0::unk168: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk11696e0
{
public:
    bool Function11696e0();
    std::uint8_t unknown00[360];
    std::uint32_t unk168;
};
static_assert(offsetof(Unk11696e0, unk168) == 360, "field offset");
