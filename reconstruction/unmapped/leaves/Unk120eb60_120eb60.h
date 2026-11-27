// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk120eb60: STANDIN GUESS(low)
// Unk120eb60::Function120eb60: GUESS(low)
// Unk120eb60::a, Unk120eb60::b, Unk120eb60::c, Unk120eb60::d: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk120eb60
{
public:
    bool Function120eb60();
    float a;
    float b;
    float c;
    float d;
};
static_assert(offsetof(Unk120eb60, a) == 0, "field offset");
static_assert(offsetof(Unk120eb60, b) == 4, "field offset");
static_assert(offsetof(Unk120eb60, c) == 8, "field offset");
static_assert(offsetof(Unk120eb60, d) == 12, "field offset");
