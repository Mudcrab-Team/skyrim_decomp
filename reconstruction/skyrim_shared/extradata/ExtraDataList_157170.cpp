// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function157170: GUESS(low); provisional member name
// 0x157170 ExtraDataList::Function157170
// CI hash: 0x157170 ?Function157170@ExtraDataList@@QEAAXPEAUExtra157170@@PEAV1@@Z
#include "ExtraDataList_157170.h"

// Guess: Transfer an extra-data record between lists.
void ExtraDataList::Function157170(Extra157170* value, ExtraDataList* destination)
{
    if (value && destination) {
        Remove(value, false);
        value->next = nullptr;
        destination->Add(value);
    }
}
