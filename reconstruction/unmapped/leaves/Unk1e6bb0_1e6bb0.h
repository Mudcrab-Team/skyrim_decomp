// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk1e6bb0: GUESS(low)
// Unk1e6bb0::Function1e6bb0: GUESS(low)
// Unk1e6bb0::unk14, Unk1e6bb0::kTestMask: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1e6bb0
{
public:
    static constexpr std::uint32_t kTestMask = 0xffffff;
    bool Function1e6bb0(std::uint32_t value);
    std::uint8_t unknown00[20];
    std::uint32_t unk14;
};
static_assert(offsetof(Unk1e6bb0, unk14) == 20, "field offset");
