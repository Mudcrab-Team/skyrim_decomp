// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk561c00: STANDIN GUESS(low)
// Unk561c00::Function561c00: GUESS(low)
// Unk561c00::unknown0, Unk561c00::target, FlagTarget561c00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FlagTarget561c00 { std::uint8_t unknown00[452]; std::uint8_t flag; };


class Unk561c00
{
public:
    void Function561c00(std::uint8_t value);
    std::uint8_t unknown0[16];
    FlagTarget561c00* target;
};
static_assert(offsetof(Unk561c00, target) == 16, "field offset");
