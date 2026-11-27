// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk45c380: STANDIN GUESS(low)
// Unk45c380::Function45c380: GUESS(low)
// Unk45c380::values, Unk45c380::direct: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

union Value45c380 { std::uint64_t value; std::uint8_t kind; };
std::uint64_t Resolve45c380(void* context, std::uint8_t kind);
class Unk45c380
{
public:
    std::uint64_t Function45c380(std::uint32_t index, void* context);
    Value45c380* values;
    std::uint8_t unknown8[16];
    std::uint8_t direct;
};
static_assert(offsetof(Unk45c380, values) == 0, "field offset");
static_assert(offsetof(Unk45c380, direct) == 24, "field offset");
