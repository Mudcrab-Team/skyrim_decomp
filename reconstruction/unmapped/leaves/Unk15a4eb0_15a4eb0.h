// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15a4eb0: STANDIN GUESS(low)
// Unk15a4eb0::Function15a4eb0: GUESS(low)
// Unk15a4eb0::data, Unk15a4eb0::hasData, DiffMorph15a4eb0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct DiffMorph15a4eb0 { std::uint32_t unknown00[14]; };

class Unk15a4eb0
{
public:
    std::uintptr_t Function15a4eb0(void* context, std::uint32_t index);
    DiffMorph15a4eb0* data;
    std::uint8_t unknown8[8];
    std::uint32_t hasData;
};
static_assert(offsetof(Unk15a4eb0, data) == 0, "field offset");
static_assert(offsetof(Unk15a4eb0, hasData) == 16, "field offset");
