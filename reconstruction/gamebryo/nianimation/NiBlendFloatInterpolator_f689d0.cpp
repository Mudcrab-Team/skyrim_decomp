// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf689d0 NiBlendFloatInterpolator::Ctor
// CI hash: 0xf689d0 ??0NiBlendFloatInterpolator@@QEAA@_NEM@Z
// 0xf68be0 NiBlendFloatInterpolator::Ctor
// CI hash: 0xf68be0 ??0NiBlendFloatInterpolator@@QEAA@XZ
// 0xf68c40 NiBlendFloatInterpolator::UpdateFloat
// Adapted bodies: none
#include "NiBlendFloatInterpolator_f689d0.h"

extern const float gDefaultValue;
extern const float gInvalidTime;

NiBlendFloatInterpolator::NiBlendFloatInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold) :
    NiBlendInterpolator(managerControlled, capacity, weightThreshold), value(gDefaultValue)
{

}

NiBlendFloatInterpolator::NiBlendFloatInterpolator() :
    value(gDefaultValue)
{

}

bool NiBlendFloatInterpolator::UpdateFloat(float time, NiObjectNET* target, float& result)
{
    if ((flags & 1) != 0) {
        time = cachedTime;
    }
    if (time == gInvalidTime) {
        return false;
    }
    if (source->UpdateFloat(time, target, value)) {
        result = value;
        return true;
    }
    value = gDefaultValue;
    result = gDefaultValue;
    return false;
}
