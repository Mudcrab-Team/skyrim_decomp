// Source exposure: mixed (pinned image listing; community source; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry229040::HasAnyFlag, treated as adapted: shaped like InventoryEntryData::IsQuestObject (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/I/InventoryEntryData.cpp:246, MIT); ItemChange::HasStolenData in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:289
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x229040 InventoryEntry229040::HasAnyFlag
#include "InventoryEntry229040.h"

// Return true if any extra data list has the flag set.
bool InventoryEntry229040::HasAnyFlag() const
{
    bool found = false;
    for (ExtraListNode229040* node = extraLists; !found && node && node->item; node = node->next)
    {
        found = node->item->HasFlag();
    }
    return found;
}
