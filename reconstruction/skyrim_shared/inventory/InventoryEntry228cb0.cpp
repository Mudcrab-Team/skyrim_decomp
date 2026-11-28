// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228cb0::GetExtraPtr, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228cb0 InventoryEntry228cb0::GetExtraPtr
#include "InventoryEntry228cb0.h"

// Return the extra pointer from the first extra data list, or null when absent.
void* InventoryEntry228cb0::GetExtraPtr() const
{
    if (extraLists)
    {
        ExtraDataList228cb0* list = extraLists->item;
        if (list && list->GetExtraPtr())
        {
            return list->GetExtraPtr();
        }
    }
    return nullptr;
}
