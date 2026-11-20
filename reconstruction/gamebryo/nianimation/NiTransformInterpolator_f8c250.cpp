// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf8c250 NiTransformInterpolator::CopyExtendedState
// Adapted bodies: none
#include "NiTransformInterpolator_f8c250.h"

void NiTransformInterpolator::CopyExtendedState(NiTransformInterpolator* dest) const
{
    CopyMembers(dest);
    dest->extendedState = extendedState;
}
