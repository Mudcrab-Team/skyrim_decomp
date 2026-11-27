// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8420: GUESS(low)
// Unk6e8420::Function6e8420: GUESS(low)
// Unk6e8420::unk4c, Unk6e8420::kFieldMask0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk6e8420
{
public:
    static constexpr std::uint32_t kFieldMask0 = 0x1ff;
    std::uint32_t Function6e8420();
    std::uint8_t unknown00[76];
    std::uint32_t unk4c;
};
static_assert(offsetof(Unk6e8420, unk4c) == 76, "field offset");
