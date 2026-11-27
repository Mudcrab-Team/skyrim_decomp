// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk11eaaa0: STANDIN GUESS(low)
// Unk11eaaa0::Function11eaaa0: GUESS(low)
// Unk11eaaa0::unknown0, Unk11eaaa0::unk28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk11eaaa0
{
public:
    bool Function11eaaa0(void** output);
    std::uint8_t unknown0[40];
    void* unk28;
};
static_assert(offsetof(Unk11eaaa0, unk28) == 40, "field offset");
