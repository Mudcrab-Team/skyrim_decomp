// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk632c40: STANDIN GUESS(low)
// Unk632c40::Function632c40: GUESS(low)
// Unk632c40::first, Unk632c40::second, ValuePair632c40: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ValuePair632c40 { std::uint32_t first; std::uint32_t second; };

class Unk632c40
{
public:
    bool Function632c40(const ValuePair632c40& other);
    std::uint32_t first;
    std::uint32_t second;
};
static_assert(offsetof(Unk632c40, first) == 0, "field offset");
static_assert(offsetof(Unk632c40, second) == 4, "field offset");
