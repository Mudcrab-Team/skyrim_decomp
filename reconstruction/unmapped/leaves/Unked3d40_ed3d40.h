// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unked3d40: STANDIN GUESS(low)
// Unked3d40::Unked3d40: GUESS(low)
// Unked3d40::unk00, Unked3d40::unk04: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unked3d40
{
public:
    Unked3d40(std::uint32_t first, std::uint32_t second);
    std::uint32_t unk00;
    std::uint32_t unk04;
};
static_assert(offsetof(Unked3d40, unk00) == 0, "field offset");
static_assert(offsetof(Unked3d40, unk04) == 4, "field offset");
