// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xcfbd40 BSGamepadDevice::Functioncfbd40
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "BSGamepadDevice_cfbd40.h"

// kMaxValue: GUESS(low); analog stick raw range
static const float kMaxValue = 32767.0f;

float BSGamepadDevice::Functioncfbd40(int raw, float threshold)
{
    const float maxValue = kMaxValue;
    const float low = threshold * maxValue;
    if (raw < low || low == maxValue) {
        return 0.0f;
    }
    return (raw - low) / (maxValue - low);
}
