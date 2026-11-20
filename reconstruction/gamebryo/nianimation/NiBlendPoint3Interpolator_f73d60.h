// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendPoint3Interpolator: EXE_RTTI
// value, gDefaultValue, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
public:
    NiBlendPoint3Interpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    NiBlendPoint3Interpolator();

private:
    NiPoint3 value;
    bool valid;
};
