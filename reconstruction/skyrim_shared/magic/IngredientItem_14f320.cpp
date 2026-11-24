// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14f320 IngredientItem::ClearCachedEntries
// Adapted bodies: none
#include "IngredientItem_14f320.h"
// ArrayEntry: STANDIN GUESS(low); only the owned pointer and cleanup call are modelled.
// ArrayEntry::ClearEntry, ArrayEntry::owner, ArrayEntry::unk00, g_entries, g_entryCount, g_entryField1, g_entryField2: GUESS(low)
#include <cstdint>

struct ArrayEntry
{
    void* unk00;
    void* owner;
    void ClearEntry(ArrayEntry* entry);
};

extern ArrayEntry* g_entries;
extern std::uint32_t g_entryCount;
extern std::uint32_t g_entryField1;
extern std::uint32_t g_entryField2;

void IngredientItem::ClearCachedEntries()
{
    ArrayEntry* entry = g_entries;
    if (entry) {
        if (std::uint32_t remaining = g_entryCount) {
            do {
                --remaining;
                if (entry->owner) {
                    entry->ClearEntry(entry);
                    entry->owner = nullptr;
                }
                ++entry;
            } while (remaining);
        }
    } else {
        g_entryCount = 0;
    }
    const std::uint32_t count = g_entryCount;
    g_entryField1 = count;
    g_entryField2 = count;
}
