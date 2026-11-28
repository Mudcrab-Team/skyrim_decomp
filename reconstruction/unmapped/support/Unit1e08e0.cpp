// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e08e0 Unit1e08e0::RemoveAndDeleteEntry1e08e0
// Adapted bodies: none
#include "Unit1e08e0.h"

// Removes the entry from the array under a scoped thread-local context tag and deletes both payload and entry.
void Unit1e08e0::RemoveAndDeleteEntry1e08e0(ListEntry1e08e0* a_entry)
{
    ScopedContextTag1e08e0 guard(0x65);
    if (a_entry) {
        for (std::uint32_t i = 0; i < count; ++i) {
            if (items[i] == a_entry) {
                for (std::uint32_t j = i; j < count - 1; ++j) {
                    items[j] = items[j + 1];
                }
                i = count;
                --count;
            }
        }
        delete a_entry->payload;
        delete a_entry;
    }
}
