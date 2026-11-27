// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSStoryEventManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function533200: GUESS(low); provisional member name
// 0x533200 BGSStoryEventManager::Function533200
// CI hash: 0x533200 ?Function533200@BGSStoryEventManager@@QEAAII@Z
#include "BGSStoryEventManager_533200.h"

// Guess: Find the story-event value in its chained hash table.
unsigned BGSStoryEventManager::Function533200(unsigned key)
{
    unsigned hash;
    HashStoryKey(&hash, key);
    if (entries) {
        auto* entry = &entries[hash & (capacity - 1)];
        if (entry->next) {
            do {
                if (entry->key == key) { return entry->value; }
                entry = entry->next;
            } while (entry != sentinel);
        }
    }
    return ~0u;
}
