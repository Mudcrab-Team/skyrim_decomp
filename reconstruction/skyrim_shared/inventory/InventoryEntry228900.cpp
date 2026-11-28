// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry228900::GetEnchantment, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x228900 InventoryEntry228900::GetEnchantment
#include "InventoryEntry228900.h"

// Return the enchantment on the first extra data list, or null when absent.
void* InventoryEntry228900::GetEnchantment() const
{
    if (extraLists)
    {
        ExtraDataList228900* list = extraLists->item;
        if (list && list->GetEnchantment())
        {
            return list->GetEnchantment();
        }
    }
    return nullptr;
}
