// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk120f780: STANDIN GUESS(low)
// Unk120f780::Function120f780: GUESS(low)
// FloatScale120f780: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FloatScale120f780 { std::uint8_t unknown00[20]; float factor; };

class Unk120f780
{
public:
    static float Function120f780(float value, const FloatScale120f780* scale);
};
