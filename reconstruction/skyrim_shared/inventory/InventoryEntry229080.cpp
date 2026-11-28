// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InventoryEntry229080::CountFlagged, treated as adapted: shaped like ItemChange::GetExtraTotalCount in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/inventorychanges.cpp:353
// SPDX-License-Identifier: CC0-1.0
// 0x229080 InventoryEntry229080::CountFlagged
#include "InventoryEntry229080.h"

// Sum the stack counts of all extra data lists that carry the flag.
std::int32_t InventoryEntry229080::CountFlagged() const
{
    std::int32_t total = 0;
    for (ExtraListNode229080* node = extraLists; node; node = node->next)
    {
        ExtraDataList229080* list = node->item;
        if (!list)
        {
            break;
        }
        if (list->HasFlag())
        {
            total += list->GetCount();
        }
    }
    return total;
}
