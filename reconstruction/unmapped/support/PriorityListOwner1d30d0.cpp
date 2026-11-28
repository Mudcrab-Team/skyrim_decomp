// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1d30d0 PriorityListOwner1d30d0::SortByPriority1d30d0
// Adapted bodies: none
#include "PriorityListOwner1d30d0.h"

// Sorts the owned entry pointer array in descending order of entry priority while preserving relative order.
void PriorityListOwner1d30d0::SortByPriority1d30d0()
{
    if (!list || list->count == 0) {
        return;
    }

    for (std::uint32_t i = 0; i < static_cast<std::uint32_t>(list->count) - 1; ++i) {
        std::uint32_t best = i;
        for (std::uint32_t j = i + 1; j < list->count; ++j) {
            if (list->items[j]->priority > list->items[best]->priority) {
                best = j;
            }
        }
        PriorityEntry1d30d0* chosen = list->items[best];
        for (std::uint32_t k = best; k > i; --k) {
            list->items[k] = list->items[k - 1];
        }
        list->items[i] = chosen;
    }
}
