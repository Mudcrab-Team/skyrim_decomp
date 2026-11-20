// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf72bc0 NiBlendBoolInterpolator::Ctor
// CI hash: 0xf72bc0 ??0NiBlendBoolInterpolator@@QEAA@_NEM@Z
// 0xf72df0 NiBlendBoolInterpolator::Ctor
// CI hash: 0xf72df0 ??0NiBlendBoolInterpolator@@QEAA@XZ
// 0xf72e50 NiBlendBoolInterpolator::UpdateBool
// Adapted bodies: none
#include "NiBlendBoolInterpolator_f72bc0.h"

extern const bool gDefaultValue;
extern const float gInvalidTime;

NiBlendBoolInterpolator::NiBlendBoolInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold) :
    NiBlendInterpolator(managerControlled, capacity, weightThreshold), value(gDefaultValue)
{

}

NiBlendBoolInterpolator::NiBlendBoolInterpolator() :
    value(gDefaultValue)
{

}

bool NiBlendBoolInterpolator::UpdateBool(float time, NiObjectNET* target, bool& result)
{
    if ((flags & 1) != 0) {
        time = cachedTime;
    }
    if (time == gInvalidTime) {
        return false;
    }
    if (source->UpdateBool(time, target, result)) {
        value = result;
        return true;
    }
    result = false;
    value = gDefaultValue;
    return false;
}
