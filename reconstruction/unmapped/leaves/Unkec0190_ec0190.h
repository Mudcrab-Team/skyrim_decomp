// Source exposure: binary-analysis.
// Code origin: original scalar storage reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unkec0190: STANDIN GUESS(low)
// Unkec0190::Unkec0190: GUESS(low)
// Unkec0190::unk00, Unkec0190::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class Unkec0190
{
public:
    Unkec0190();
    std::uint32_t unk00;
    std::uint8_t unknown04[4];
    std::uint64_t unk08;
};
static_assert(offsetof(Unkec0190, unk00) == 0, "field offset");
static_assert(offsetof(Unkec0190, unk08) == 8, "field offset");
