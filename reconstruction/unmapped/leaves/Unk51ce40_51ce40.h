// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk51ce40: STANDIN GUESS(low)
// Unk51ce40::Unk51ce40: GUESS(low)
// Unk51ce40::unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk51ce40
{
public:
    Unk51ce40(std::uint64_t first);
    std::uint64_t unk00;
};
static_assert(offsetof(Unk51ce40, unk00) == 0, "field offset");
