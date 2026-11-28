// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x277ad0 Obj277ad0::Function277ad0
// Adapted bodies: none
#include "Obj277ad0.h"

#include <cmath>

// Computes half the XY diagonal length of the 16-bit integer bounding box.
float Obj277ad0::Function277ad0() const
{
    std::int16_t dx = maxX - minX;
    std::int16_t dy = maxY - minY;
    return std::sqrtf(static_cast<float>(dy * dy + dx * dx)) * 0.5f;
}
