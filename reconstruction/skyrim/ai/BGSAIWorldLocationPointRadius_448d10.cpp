// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x448d10 BGSAIWorldLocationPointRadius::GetDistanceSquared
// Adapted bodies: none
#include "BGSAIWorldLocationPointRadius_448d10.h"

float BGSAIWorldLocationPointRadius::GetDistanceSquared(const PositionHolder& a_other)
{
    float result = 3.402823466e+38f;
    if (HasLocation()) {
        float dx = posX - a_other.x;
        float dy = posY - a_other.y;
        float dz = posZ - a_other.z;
        result = dx * dx + dy * dy + dz * dz;
    }
    return result;
}
