// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk1cc700: GUESS(low)
// Unk1cc700::Function1cc700: GUESS(low)
// Unk1cc700::unk478: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Unk1cc700
{
public:
    bool Function1cc700();
    std::uint8_t unknown00[1144];
    std::uint8_t unk478;
};
static_assert(offsetof(Unk1cc700, unk478) == 1144, "field offset");
