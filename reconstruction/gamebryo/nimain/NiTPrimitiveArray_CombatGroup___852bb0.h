// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// NiTPrimitiveArray_CombatGroup__: GUESS(low)
// NiTPrimitiveArray_CombatGroup__::Function852bb0: GUESS(low)
// NiTPrimitiveArray_CombatGroup__::unk5c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiTPrimitiveArray_CombatGroup__
{
public:
    void Function852bb0();
    std::uint8_t unknown00[92];
    std::uint32_t unk5c;
};
static_assert(offsetof(NiTPrimitiveArray_CombatGroup__, unk5c) == 92, "field offset");
