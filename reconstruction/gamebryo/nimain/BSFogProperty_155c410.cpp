// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x155c410 BSFogProperty::SetNearFarFromScale
// Adapted bodies: none
#include "BSFogProperty_155c410.h"

void BSFogProperty::SetNearFarFromScale(float a_scale)
{
    a_scale *= fFogScaleFactor;
    fFar = 163840.0f;
    fNear = fFogNearBase - a_scale;
}
