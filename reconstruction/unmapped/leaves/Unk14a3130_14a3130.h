// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk14a3130: STANDIN GUESS(low)
// Unk14a3130::Unk14a3130: GUESS(low)
// Unk14a3130::unk00, Unk14a3130::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unk14a3130
{
public:
    Unk14a3130();
    std::uint64_t unk00;
    std::uint64_t unk08;
};
static_assert(offsetof(Unk14a3130, unk00) == 0, "field offset");
static_assert(offsetof(Unk14a3130, unk08) == 8, "field offset");
