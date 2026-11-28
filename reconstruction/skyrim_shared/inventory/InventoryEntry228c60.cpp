// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228c60::FindWornExtraList, treated as adapted: shaped like InventoryEntryData::IsWorn (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:223, MIT); ItemChange::GetWorn in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:505
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228c60 InventoryEntry228c60::FindWornExtraList
#include "InventoryEntry228c60.h"

// Return the first extra data list marked as worn, or null when none matches.
ExtraDataList228c60* InventoryEntry228c60::FindWornExtraList() const
{
    ExtraDataList228c60* found = nullptr;
    for (ExtraListNode228c60* node = extraLists; !found && node && node->item; node = node->next)
    {
        if (node->item->IsWorn())
        {
            found = node->item;
        }
    }
    return found;
}
