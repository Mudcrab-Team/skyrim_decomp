// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1efd70 Unit1efd70::FindMinScore1efd70
// Adapted bodies: none
#include "Unit1efd70.h"

#include <climits>

// Walks the linked list and returns the lowest score among entries accepted by the optional filter.
std::int32_t Unit1efd70::FindMinScore1efd70(void** a_outObject, bool (*a_filter)(void*, void*), void* a_userData) const
{
    std::int32_t best = INT_MAX;
    const ListNode1efd70* node = &head;
    while (node && node->item) {
        ListEntry1efd70* entry = node->item;
        if (!a_filter || a_filter(entry->object, a_userData)) {
            if (entry->score < best) {
                best = entry->score;
                if (a_outObject) {
                    *a_outObject = entry->object;
                }
            }
        }
        node = node->next;
    }
    return best != INT_MAX ? best : 0;
}
