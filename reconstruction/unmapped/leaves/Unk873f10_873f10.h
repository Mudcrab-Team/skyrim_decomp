// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk873f10: GUESS(low)
// Unk873f10::Function873f10: GUESS(low)
// Unk873f10::unk00: GUESS(low)
// LinkedFields873f10: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class LinkedFields873f10
{
public:
    std::uint64_t unk00;
};
class Unk873f10
{
public:
    std::uint64_t Function873f10();
    LinkedFields873f10* unk00;
};
static_assert(offsetof(Unk873f10, unk00) == 0, "field offset");
