// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk2b6540: STANDIN GUESS(low)
// Unk2b6540::Function2b6540: GUESS(low)
// Unk2b6540::x, Unk2b6540::y, Unk2b6540::z, gMinimumLength2b6540, gUnit2b6540: GUESS(low)
// 0x2b6540 Unk2b6540::Function2b6540
#include "Unk2b6540_2b6540.h"

// Normalize the vector, clearing a vector below the length threshold.
void Unk2b6540::Function2b6540()
{
    const float length = sqrtf(x * x + y * y + z * z);
    if (length > gMinimumLength2b6540)
    {
        const float scale = gUnit2b6540 / length;
        x = x * scale;
        y = y * scale;
        z = z * scale;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
}
