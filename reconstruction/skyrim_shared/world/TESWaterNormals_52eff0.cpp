// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x52eff0 TESWaterNormals::dtor_deleting
// CI hash: 0x52eff0 ??_GTESWaterNormals@@UEAAPEAXI@Z
#include "TESWaterNormals_52eff0.h"

TESWaterNormals::TESWaterNormals()
{
}

TESWaterNormals::~TESWaterNormals()
{
    noiseLayer0 = nullptr;
    noiseLayer1 = nullptr;
    noiseLayer2 = nullptr;
}
