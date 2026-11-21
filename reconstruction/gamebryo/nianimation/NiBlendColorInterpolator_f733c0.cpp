// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf734f0 NiBlendColorInterpolator::Ctor
// CI hash: 0xf734f0 ??0NiBlendColorInterpolator@@QEAA@_NEM@Z
// 0xf73600 NiBlendColorInterpolator::Ctor
// CI hash: 0xf73600 ??0NiBlendColorInterpolator@@QEAA@XZ
// 0xf733c0 NiBlendColorInterpolator::IsEqual
// 0xf73660 NiBlendColorInterpolator::UpdateColor
// Adapted bodies: none
#include "NiBlendColorInterpolator_f733c0.h"

extern const NiColorA gDefaultValue;
extern const float gInvalidTime;

NiBlendColorInterpolator::NiBlendColorInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold) :
    NiBlendInterpolator(managerControlled, capacity, weightThreshold), value(gDefaultValue), valid(false)
{

}

NiBlendColorInterpolator::NiBlendColorInterpolator() :
    value(gDefaultValue), valid(false)
{

}

bool NiBlendColorInterpolator::IsEqual(NiObject* object)
{
    if (!NiBlendInterpolator::IsEqual(object)) {
        return false;
    }
    const auto* other = static_cast<const NiBlendColorInterpolator*>(object);
    if (value.red != other->value.red) {
        return false;
    }
    if (value.green != other->value.green) {
        return false;
    }
    if (value.blue != other->value.blue) {
        return false;
    }
    if (value.alpha != other->value.alpha) {
        return false;
    }
    return true;
}

bool NiBlendColorInterpolator::UpdateColor(float time, NiObjectNET* target, NiColorA& result)
{
    if ((flags & 1) != 0) {
        time = cachedTime;
    }
    if (time == gInvalidTime) {
        return false;
    }
    if (source->UpdateColor(time, target, value)) {
        result = value;
        return true;
    }
    const auto invalid = gDefaultValue;
    result = invalid;
    value = invalid;
    return false;
}
