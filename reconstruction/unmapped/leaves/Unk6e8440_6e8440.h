// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8440: GUESS(low)
// Unk6e8440::Function6e8440: GUESS(low)
// Unk6e8440::unk4c, Unk6e8440::kShift0, Unk6e8440::kFieldMask1: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6e8440
{
public:
    static constexpr std::uint32_t kShift0 = 13;
    static constexpr std::uint32_t kFieldMask1 = 0x3fff;
    std::uint32_t Function6e8440();
    std::uint8_t unknown00[76];
    std::uint32_t unk4c;
};
static_assert(offsetof(Unk6e8440, unk4c) == 76, "field offset");
