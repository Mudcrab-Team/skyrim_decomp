// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15a5140: STANDIN GUESS(low)
// Unk15a5140::Function15a5140: GUESS(low)
// Unk15a5140::data, Unk15a5140::hasData, StatMorph15a5140: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct StatMorph15a5140 { std::uint32_t unknown00[12]; };

class Unk15a5140
{
public:
    std::uintptr_t Function15a5140(void* context, std::uint32_t index);
    std::uint8_t unknown0[24];
    StatMorph15a5140* data;
    std::uint8_t unknown20[8];
    std::uint32_t hasData;
};
static_assert(offsetof(Unk15a5140, data) == 24, "field offset");
static_assert(offsetof(Unk15a5140, hasData) == 40, "field offset");
