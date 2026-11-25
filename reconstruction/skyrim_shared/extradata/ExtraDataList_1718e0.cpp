// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1718e0: GUESS(low); provisional member name
// 0x1718e0 ExtraDataList::Function1718e0
// CI hash: 0x1718e0 ?Function1718e0@ExtraDataList@@QEAAXPEAX@Z
#include "ExtraDataList_1718e0.h"

// Guess: Remove a member of a protected extra record and discard the record when empty.
void ExtraDataList::Function1718e0(void* value)
{
    Scope1718e0 scope(0x61);
    Guard1718e0 guard(&lock);
    if (auto* extra = GetByType(0x78)) {
        extra->Remove(value);
        if (extra->Empty()) { RemoveExtra(extra, true); }
    }
}
