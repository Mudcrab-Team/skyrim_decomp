// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendFloatInterpolator: EXE_RTTI
// value, gDefaultValue, gInvalidTime, UpdateFloat: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendFloatInterpolator : public NiBlendInterpolator
{
public:
    NiBlendFloatInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    NiBlendFloatInterpolator();
    bool UpdateFloat(float time, NiObjectNET* target, float& result);

private:
    float value;
};
