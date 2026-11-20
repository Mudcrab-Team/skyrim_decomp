// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf3dca0 NiUnionBV::Differs
// Adapted bodies: none
#include "NiUnionBV_f3dca0.h"

bool NiUnionBV::Differs(const NiBoundingVolume& other) const
{
    return !Slot09(other);
}
