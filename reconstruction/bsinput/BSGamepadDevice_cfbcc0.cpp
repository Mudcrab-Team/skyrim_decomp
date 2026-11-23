// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xcfbcc0 BSGamepadDevice::Functioncfbcc0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "BSGamepadDevice_cfbcc0.h"
#include <cmath>
void BSGamepadDevice::Functioncfbcc0(float x, float y, float deadzone, float maxMagnitude, float* outX, float* outY)
{
    const float magnitude = std::sqrt(x * x + y * y);
    float scale;
    if (magnitude > 0.0f) {
        float t = (magnitude - deadzone) / (maxMagnitude - deadzone);
        t = t < 0.0f ? 0.0f : t;
        scale = (t < 1.0f ? t : 1.0f) / magnitude;
    } else {
        scale = 0.0f;
    }
    *outX = scale * x;
    *outY = scale * y;
}
