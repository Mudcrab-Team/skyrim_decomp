// Near miss: 70.73% | inline-set
// Exposure detail: (community declarations and pinned image analysis).
// Source exposure: mixed
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x23bcd0 InventoryChanges::AddCountToExistingEntry

#include "include/23bcd0/InventoryChanges_23bcd0.h"

void InventoryChanges::AddCountToExistingEntry(TESBoundObject* object, std::int32_t count)
{
    auto* node = entryList;
    bool searching = true;
    while (node && searching) {
        if (node->item && node->item->object == object) {
            searching = false;
        } else {
            node = node->next;
        }
    }
    if (node && node->item) {
        node->item->countDelta += count;
    }
}
