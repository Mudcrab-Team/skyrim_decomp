// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf75940 NiBoolInterpolator::IsEqual
// Adapted bodies: none
#include "NiBoolInterpolator_f75940.h"

bool NiBoolInterpolator::IsEqual(NiObject* object)
{
    if (!NiKeyBasedInterpolator::IsEqual(object)) {
        return false;
    }
    auto* other = static_cast<NiBoolInterpolator*>(object);
    if (value != other->value) {
        return false;
    }
    auto* localData = data.pointer;
    auto* otherData = other->data.pointer;
    if (localData) {
        if (!otherData || !localData->IsEqual(otherData)) {
            return false;
        }
    } else if (otherData) {
        return false;
    }
    return true;
}
