// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk1555400: GUESS(low)
// Unk1555400::Function1555400: GUESS(low)
// Unk1555400::unk10: GUESS(low)
// LinkedFields1555400: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class LinkedFields1555400
{
public:
    std::uint8_t unknown00[288];
    std::uint64_t unk120;
};
class Unk1555400
{
public:
    std::uint64_t Function1555400();
    std::uint8_t unknown00[16];
    LinkedFields1555400* unk10;
};
static_assert(offsetof(Unk1555400, unk10) == 16, "field offset");
