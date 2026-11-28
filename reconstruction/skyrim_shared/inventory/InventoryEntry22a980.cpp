// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry22a980::GetEntryA, GetEntryB and GetStatusFlags, treated as adapted: shaped like InventoryEntryData::GetOwner (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:141, MIT); ItemChange::GetItemOwnership and ItemChange::GetPoison in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1376
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:1449
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x22a980 InventoryEntry22a980::GetStatusFlags
#include "InventoryEntry22a980.h"

// Compute status bitflags indicating ownership, enchantment, and extra state on the entry.
std::uint32_t InventoryEntry22a980::GetStatusFlags() const
{
    std::uint32_t flags = 0;
    if (GetEntryA() && GetEntryA() != gPlayer22a980->unk40)
    {
        flags = 1;
    }
    ExtraDataList22a980* first = extraLists ? extraLists->item : nullptr;
    if (GetCombinedExtra22a980(object, first))
    {
        flags |= 2;
    }
    if (GetEntryB())
    {
        flags |= 4;
    }
    return flags;
}
