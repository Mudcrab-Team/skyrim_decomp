// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk704c30: GUESS(low)
// Unk704c30::Function704c30: GUESS(low)
// Unk704c30::unk10, Unk704c30::kStep0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk704c30
{
public:
    static constexpr std::uint64_t kStep0 = 568;
    std::uint64_t Function704c30();
    std::uint8_t unknown00[16];
    std::uint64_t unk10;
};
static_assert(offsetof(Unk704c30, unk10) == 16, "field offset");
