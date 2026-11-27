// Source exposure: binary-analysis.
// Code origin: original value-storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk2591e0: STANDIN GUESS(low)
// Unk2591e0::Unk2591e0: GUESS(low)
// Unk2591e0::unk00, Unk2591e0::unk04: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk2591e0
{
public:
    Unk2591e0(const Unk2591e0& other);
    std::uint32_t unk00;
    std::uint32_t unk04;
};
static_assert(offsetof(Unk2591e0, unk00) == 0, "field offset");
static_assert(offsetof(Unk2591e0, unk04) == 4, "field offset");
