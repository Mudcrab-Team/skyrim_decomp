// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x251400 TESRegionDataList::Find
// Adapted bodies: TESRegionDataList::Find follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataList.cpp:200
#include "TESRegionDataList_251400.h"

TESRegionData* TESRegionDataList::Find(RegionDataType aFind)
{
    TESRegionDataList* pCurrent = this;
    while (pCurrent)
    {
        TESRegionData* pItem = pCurrent->m_item;
        if (pItem && pItem->GetType() == aFind)
            return pItem;
        pCurrent = pCurrent->m_pkNext;
    }
    return nullptr;
}
