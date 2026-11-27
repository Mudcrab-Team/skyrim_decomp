// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk14dcfd0: STANDIN GUESS(low)
// Unk14dcfd0::Unk14dcfd0: GUESS(low)
// Unk14dcfd0::unk00, Unk14dcfd0::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk14dcfd0
{
public:
    Unk14dcfd0();
    std::uint64_t unk00;
    std::uint32_t unk08;
};
static_assert(offsetof(Unk14dcfd0, unk00) == 0, "field offset");
static_assert(offsetof(Unk14dcfd0, unk08) == 8, "field offset");
