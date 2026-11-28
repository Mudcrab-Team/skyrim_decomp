// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1efe00 Unit1efe00::FindMaxScore1efe00
// Adapted bodies: none
#include "Unit1efe00.h"

#include <climits>

// Walks the linked list and returns the highest score among entries accepted by the optional filter.
std::int32_t Unit1efe00::FindMaxScore1efe00(void** a_outObject, bool (*a_filter)(void*, void*), void* a_userData) const
{
    std::int32_t best = INT_MIN;
    const ListNode1efe00* node = &head;
    while (node && node->item) {
        ListEntry1efe00* entry = node->item;
        if (!a_filter || a_filter(entry->object, a_userData)) {
            if (entry->score > best) {
                best = entry->score;
                if (a_outObject) {
                    *a_outObject = entry->object;
                }
            }
        }
        node = node->next;
    }
    return best != INT_MIN ? best : 0;
}
