// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2514b0 TESRegionDataList::Initialize
// Adapted bodies: TESRegionDataList::Initialize follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataList.cpp:225
#include "TESRegionDataList_2514b0.h"

// The loop does not advance: the listing re-reads the head item on every pass.
void TESRegionDataList::Initialize(TESRegion* apRegion)
{
    while (this && m_item)
        m_item->LoadData(apRegion);
}
