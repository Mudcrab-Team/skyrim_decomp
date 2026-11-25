// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1719a0: GUESS(low); provisional member name
// 0x1719a0 ExtraDataList::Function1719a0
// CI hash: 0x1719a0 ?Function1719a0@ExtraDataList@@QEAAXPEAX0@Z
#include "ExtraDataList_1719a0.h"

// Guess: Update an optional extra-data entry under a read lock.
void ExtraDataList::Function1719a0(void* first, void* second)
{
    Guard1719a0 guard(&lock);
    if (auto* value = GetByType(0x78)) { value->Apply(first, second); }
}
