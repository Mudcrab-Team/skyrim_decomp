// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock17b5d0: GUESS(low) STANDIN; original owner is unknown
// Function17b5d0: GUESS(low); provisional entry name
// 0x17b5d0 Unlock17b5d0::Function17b5d0
#include "Unlock17b5d0.h"

void Unlock17b5d0::Function17b5d0()
{
    auto* value = lock;
    if (value) {
        // Acquire the owner word before checking the thread.
        _mm_lfence();
        if (value->owner == GetCurrentThreadId()) {
            if (value->count == 1) {
                value->owner = 0;
                // Publish owner release before unlocking.
                _mm_mfence();
                // Atomically drop the final recursive acquisition.
                _InterlockedCompareExchange(&value->count, 0, 1);
            } else {
                // Other acquisitions remain visible across threads.
                _InterlockedDecrement(&value->count);
            }
        }
    }
}
