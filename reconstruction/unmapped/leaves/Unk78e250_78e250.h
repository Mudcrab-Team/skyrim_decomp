// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk78e250: STANDIN GUESS(low)
// Unk78e250::Function78e250: GUESS(low)
// Unk78e250::range, FloatRange78e250: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FloatRange78e250 { float lower; float upper; };

class Unk78e250
{
public:
    bool Function78e250();
    FloatRange78e250* range;
};
static_assert(offsetof(Unk78e250, range) == 0, "field offset");
