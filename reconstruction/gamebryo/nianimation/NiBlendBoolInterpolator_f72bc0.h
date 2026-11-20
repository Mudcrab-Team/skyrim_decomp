// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendBoolInterpolator: EXE_RTTI
// value, gDefaultValue, gInvalidTime, UpdateBool: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendBoolInterpolator : public NiBlendInterpolator
{
public:
    NiBlendBoolInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    NiBlendBoolInterpolator();
    bool UpdateBool(float time, NiObjectNET* target, bool& result);

private:
    bool value;
};
