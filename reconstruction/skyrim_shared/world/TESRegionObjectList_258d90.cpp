// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x258d90 TESRegionObjectList::Copy
// Adapted bodies: TESRegionObjectList::Copy follows fo4-private@1b765c70 src/Shared/Regions/TESRegionObjectList.cpp:287
#include "TESRegionObjectList_258d90.h"

TESRegionObjectList* TESRegionObjectList::Copy(TESRegionObjectList* apCopyInto)
{
    TESRegionObjectList* pCopy = apCopyInto;
    RegionObjectNode* pNode = this ? this : 0;
    if (!apCopyInto)
    {
        pCopy = new TESRegionObjectList(bOwnsTESRegionObjectMemory);
    }
    for (; pNode; pNode = pNode->m_pkNext)
    {
        if (!pNode->m_item)
        {
            break;
        }
        if (pCopy->bOwnsTESRegionObjectMemory)
        {
            TESRegionObject* pItem = pNode->m_item->Copy(true, 0);
            if (!pCopy->Add(pItem) && pItem)
            {
                delete pItem;
            }
        }
        else
        {
            pCopy->Add(pNode->m_item);
        }
    }
    return pCopy;
}
