// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk873020: STANDIN GUESS(low)
// Unk873020::Function873020: GUESS(low)
// Unk873020::unk138, Unk873020::unk14c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk873020
{
public:
    void Function873020(std::uint64_t first);
    std::uint8_t unknown00[312];
    std::uint64_t unk138;
    std::uint8_t unknown140[12];
    std::uint32_t unk14c;
};
static_assert(offsetof(Unk873020, unk138) == 312, "field offset");
static_assert(offsetof(Unk873020, unk14c) == 332, "field offset");
