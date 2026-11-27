// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x448d90 BGSAIWorldLocationPointRadius::IsWithinRadius
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "BGSAIWorldLocationPointRadius_448d90.h"
#include <math.h>

bool BGSAIWorldLocationPointRadius::IsWithinRadius(const PositionHolder& a_other)
{
    if (!HasLocation()) {
        return false;
    }
    if (fabsf(a_other.z - posZ) > radius) {
        return false;
    }
    float dx = a_other.x - posX;
    float dy = a_other.y - posY;
    return dx * dx + dy * dy <= radius * radius;
}
