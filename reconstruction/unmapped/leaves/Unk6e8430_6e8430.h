// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8430: GUESS(low)
// Unk6e8430::Function6e8430: GUESS(low)
// Unk6e8430::unk4c, Unk6e8430::kShift0, Unk6e8430::kFieldMask1: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6e8430
{
public:
    static constexpr std::uint32_t kShift0 = 9;
    static constexpr std::uint32_t kFieldMask1 = 0xf;
    std::uint32_t Function6e8430();
    std::uint8_t unknown00[76];
    std::uint32_t unk4c;
};
static_assert(offsetof(Unk6e8430, unk4c) == 76, "field offset");
