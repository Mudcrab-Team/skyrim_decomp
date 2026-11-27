// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk2b6540: STANDIN GUESS(low)
// Unk2b6540::Function2b6540: GUESS(low)
// Unk2b6540::x, Unk2b6540::y, Unk2b6540::z, gMinimumLength2b6540, gUnit2b6540: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>


extern const float gMinimumLength2b6540;
extern const float gUnit2b6540;
class Unk2b6540
{
public:
    void Function2b6540();
    float x;
    float y;
    float z;
};
static_assert(offsetof(Unk2b6540, x) == 0, "field offset");
static_assert(offsetof(Unk2b6540, y) == 4, "field offset");
static_assert(offsetof(Unk2b6540, z) == 8, "field offset");
