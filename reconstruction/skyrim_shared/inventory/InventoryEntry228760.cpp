// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228760::GetValue, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); InventoryEntry228760::GetValue also shaped like the inventory entry script getter in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:31061
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228760 InventoryEntry228760::GetValue
#include "InventoryEntry228760.h"

// Return the value from the first extra data list carrying the extra item.
std::uint32_t InventoryEntry228760::GetValue() const
{
    for (ExtraListNode228760* node = extraLists; node && node->item; node = node->next)
    {
        ExtraDataList228760* list = node->item;
        if (list->GetExtra())
        {
            return list->GetExtra()->value10;
        }
    }
    return 0;
}
