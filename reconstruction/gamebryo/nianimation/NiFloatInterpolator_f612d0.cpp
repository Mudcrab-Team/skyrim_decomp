// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf612d0 NiFloatInterpolator::CopyMembers
// Adapted bodies: none
#include "NiFloatInterpolator_f612d0.h"

void NiFloatInterpolator::CopyMembers(NiFloatInterpolator* dest) const
{
    NiKeyBasedInterpolator::CopyMembers(dest);
    dest->floatValue = floatValue;
    dest->floatData.Reset(floatData);
    dest->lastIndex = lastIndex;
}
