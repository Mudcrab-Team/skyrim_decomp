// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendColorInterpolator: EXE_RTTI
// value, gDefaultValue, gInvalidTime, UpdateColor, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendColorInterpolator : public NiBlendInterpolator
{
public:
    NiBlendColorInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    NiBlendColorInterpolator();
    bool IsEqual(NiObject* object) override;
    bool UpdateColor(float time, NiObjectNET* target, NiColorA& result);

private:
    NiColorA value;
    bool valid;
};
