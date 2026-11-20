// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineFloatInterpolator: EXE_RTTI
// value, channelHandle: GUESS(low)
#pragma once

#include "NiBSplineInterpolator_f77f50.h"

class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
public:
    bool IsEqual(NiObject* object) override;

private:
    float value;
    std::uint32_t channelHandle;
};
