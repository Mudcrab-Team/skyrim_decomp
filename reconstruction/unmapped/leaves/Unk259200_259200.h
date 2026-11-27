// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk259200: STANDIN GUESS(low)
// Unk259200::Unk259200: GUESS(low)
// Unk259200::x, Unk259200::y: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk259200
{
public:
    Unk259200(float first, float second);
    float x;
    float y;
};
static_assert(offsetof(Unk259200, x) == 0, "field offset");
static_assert(offsetof(Unk259200, y) == 4, "field offset");
