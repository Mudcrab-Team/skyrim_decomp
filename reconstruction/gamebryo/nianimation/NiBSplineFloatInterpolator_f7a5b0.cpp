// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf7a5b0 NiBSplineFloatInterpolator::IsEqual
// Adapted bodies: none
#include "NiBSplineFloatInterpolator_f7a5b0.h"

bool NiBSplineFloatInterpolator::IsEqual(NiObject* object)
{
    if (!NiBSplineInterpolator::IsEqual(object)) {
        return false;
    }
    const auto* other = static_cast<const NiBSplineFloatInterpolator*>(object);
    if (value != other->value) {
        return false;
    }
    if (other->channelHandle != channelHandle) {
        return false;
    }
    return true;
}
