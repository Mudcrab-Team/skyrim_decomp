// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a8120 TESImageSpaceModifier::InitializeData
#include "TESImageSpaceModifier_2a8120.h"

void TESImageSpaceModifier::InitializeData()
{
    data.Clear();
    data.duration = 1.0f;
    data.radialBlurCenter = NiPoint2{ 0.5f, 0.5f };
    data.dof.useTarget = false;
    data.dof.flags = 0;
}
