// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendQuaternionInterpolator: EXE_RTTI
// value, gDefaultValue, gInvalidTime, UpdateRotation: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendQuaternionInterpolator : public NiBlendInterpolator
{
public:
    NiBlendQuaternionInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold);
    NiBlendQuaternionInterpolator();
    bool IsEqual(NiObject* object) override;
    bool UpdateRotation(float time, NiObjectNET* target, NiQuaternion& result);

private:
    NiQuaternion value;
};
