// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk8e4420: STANDIN GUESS(low)
// Unk8e4420::Function8e4420: GUESS(low)
// Unk8e4420::state, Unk8e4420::aboveThreshold, Unk8e4420::flagA, Unk8e4420::flagB, EffectState8e4420, Owner8e4420, gThreshold8e4420: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct EffectState8e4420 { std::uint8_t unknown00[192]; float distance; std::uint8_t unknownc4[12]; std::uint32_t flags; };
struct Owner8e4420 { std::uint8_t unknown00[360]; EffectState8e4420* state; };
extern const float gThreshold8e4420;
class Unk8e4420
{
public:
    void Function8e4420(const Owner8e4420& owner);
    EffectState8e4420* state;
    std::uint8_t unknown8[1];
    bool aboveThreshold;
    std::uint8_t flagA;
    std::uint8_t flagB;
};
static_assert(offsetof(Unk8e4420, state) == 0, "field offset");
static_assert(offsetof(Unk8e4420, aboveThreshold) == 9, "field offset");
static_assert(offsetof(Unk8e4420, flagA) == 10, "field offset");
static_assert(offsetof(Unk8e4420, flagB) == 11, "field offset");
