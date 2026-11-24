// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSFogProperty, BSFogProperty::SetNearFarFromScale, fFogScaleFactor, fFogNearBase, fNear, fFar: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern float fFogScaleFactor;
extern float fFogNearBase;

class BSFogProperty
{
public:
    void SetNearFarFromScale(float a_scale);  // compared: 0x155c410

    std::uint8_t unk00[0x50];
    float fNear;
    float fFar;
};
