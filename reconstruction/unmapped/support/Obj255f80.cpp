// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x255f80 Obj255f80::CosineInterpolate
// Adapted bodies: none
#include "Obj255f80.h"

#include <cmath>

// Smoothly interpolate between two floats using a cosine curve over [0, 1].
float Obj255f80::CosineInterpolate(float a, float b, float t)
{
    if (t <= 0.0f)
    {
        return a;
    }
    if (t >= 1.0f)
    {
        return b;
    }
    float factor = (1.0f - std::cosf(t * 3.1415927f)) * 0.5f;
    return (1.0f - factor) * a + factor * b;
}
