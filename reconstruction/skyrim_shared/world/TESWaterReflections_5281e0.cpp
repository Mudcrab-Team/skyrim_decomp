// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x5281e0 TESWaterReflections::~TESWaterReflections
// CI hash: 0x5281e0 ??1TESWaterReflections@@UEAA@XZ
#include "TESWaterReflections_5281e0.h"

TESWaterReflections::~TESWaterReflections()
{
    if (unk38)
    {
        unk38->Destroy(1);
        unk38 = nullptr;
    }
}
