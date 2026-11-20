// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf74830 NiBlendQuaternionInterpolator::Ctor
// CI hash: 0xf74830 ??0NiBlendQuaternionInterpolator@@QEAA@_NEM@Z
// 0xf74950 NiBlendQuaternionInterpolator::Ctor
// CI hash: 0xf74950 ??0NiBlendQuaternionInterpolator@@QEAA@XZ
// 0xf74700 NiBlendQuaternionInterpolator::IsEqual
// 0xf749b0 NiBlendQuaternionInterpolator::UpdateRotation
// Adapted bodies: none
#include "NiBlendQuaternionInterpolator_f74700.h"

extern const NiQuaternion gDefaultValue;
extern const float gInvalidTime;

NiBlendQuaternionInterpolator::NiBlendQuaternionInterpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold) :
    NiBlendInterpolator(managerControlled, capacity, weightThreshold), value(gDefaultValue)
{

}

NiBlendQuaternionInterpolator::NiBlendQuaternionInterpolator() :
    value(gDefaultValue)
{

}

bool NiBlendQuaternionInterpolator::IsEqual(NiObject* object)
{
    if (!NiBlendInterpolator::IsEqual(object)) {
        return false;
    }
    const auto* other = static_cast<const NiBlendQuaternionInterpolator*>(object);
    if (value.w != other->value.w) {
        return false;
    }
    if (value.x != other->value.x) {
        return false;
    }
    if (value.y != other->value.y) {
        return false;
    }
    if (value.z != other->value.z) {
        return false;
    }
    return true;
}

bool NiBlendQuaternionInterpolator::UpdateRotation(float time, NiObjectNET* target, NiQuaternion& result)
{
    if ((flags & 1) != 0) {
        time = cachedTime;
    }
    auto& pose = value;
    if (time != gInvalidTime && source->UpdateRotation(time, target, pose)) {
        result = pose;
        return true;
    }
    const auto invalid = gDefaultValue;
    result = invalid;
    pose = invalid;
    return false;
}
