// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Effect: GUESS(low)
// Effect::Function148a10: GUESS(low)
// Effect::unk10, Effect::kStep0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Effect
{
public:
    static constexpr std::uint64_t kStep0 = 40;
    std::uint64_t Function148a10();
    std::uint8_t unknown00[16];
    std::uint64_t unk10;
};
static_assert(offsetof(Effect, unk10) == 16, "field offset");
