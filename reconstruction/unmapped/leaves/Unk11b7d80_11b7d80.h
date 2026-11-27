// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk11b7d80: STANDIN GUESS(low)
// Unk11b7d80::Function11b7d80: GUESS(low)
// Unk11b7d80::unknown0, Unk11b7d80::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk11b7d80
{
public:
    void Function11b7d80();
    std::uint8_t unknown0[40];
    std::uint16_t value;
};
static_assert(offsetof(Unk11b7d80, value) == 40, "field offset");
