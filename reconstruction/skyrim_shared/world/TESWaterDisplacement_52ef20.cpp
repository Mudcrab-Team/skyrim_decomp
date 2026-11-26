// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x52ef20 TESWaterDisplacement::dtor_deleting
// CI hash: 0x52ef20 ??_GTESWaterDisplacement@@UEAAPEAXI@Z
#include "TESWaterDisplacement_52ef20.h"

TESWaterDisplacement::TESWaterDisplacement()
{
}

TESWaterDisplacement::~TESWaterDisplacement()
{
    if (g_waterSystemSingleton)
    {
        g_waterSystemSingleton->waterRoot->DetachChild(displacementGeometry._ptr);
    }
    displacementGeometry = nullptr;
}
