// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165460: GUESS(low); provisional member name
// 0x165460 ExtraDataList::Function165460
// CI hash: 0x165460 ?Function165460@ExtraDataList@@QEAA_NPEAX@Z
#include "ExtraDataList_165460.h"

// Guess: Search the protected extra-data list by its payload identity.
bool ExtraDataList::Function165460(void* key)
{
    Guard165460 guard(&lock);
    if (auto* extra = GetByType(0x1b)) {
        auto* node = extra->head;
        while (node) {
            auto* entry = node->value;
            if (!entry) { break; }
            if (entry->key == key) { return true; }
            node = node->next;
        }
    }
    return false;
}
