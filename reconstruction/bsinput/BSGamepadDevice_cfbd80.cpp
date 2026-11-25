// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xcfbd80 BSGamepadDevice::Functioncfbd80
// Adapted bodies: none
#include "BSGamepadDevice_cfbd80.h"

float BSGamepadDevice::Functioncfbd80(float outLow, float outHigh, float inLow, float inHigh, float value)
{
    return outLow + (outHigh - outLow) * ((value - inLow) / (inHigh - inLow));
}
