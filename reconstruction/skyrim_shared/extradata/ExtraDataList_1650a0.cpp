// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1650a0: GUESS(low); provisional member name
// 0x1650a0 ExtraDataList::Function1650a0
// CI hash: 0x1650a0 ?Function1650a0@ExtraDataList@@QEAAEPEAX@Z
#include "ExtraDataList_1650a0.h"

// Guess: Search the protected extra-data list by its payload identity.
unsigned char ExtraDataList::Function1650a0(void* key)
{
    Guard1650a0 guard(&lock);
    if (auto* extra = GetByType(0x1b)) {
        auto* node = extra->head;
        while (node) {
            auto* entry = node->value;
            if (!entry) { break; }
            if (entry->key == key) { return entry->value; }
            node = node->next;
        }
    }
    return 0xff;
}
