// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock11b6ab0: GUESS(low) STANDIN; original owner is unknown
// Function11b6ab0: GUESS(low); provisional entry name
// 0x11b6ab0 Unlock11b6ab0::Function11b6ab0
#include "Unlock11b6ab0.h"

void Unlock11b6ab0::Function11b6ab0()
{
    auto* value = pointer;
    if (value) {
        // Shared lifetime uses an atomic decrement.
        if (_InterlockedExchangeAdd(&value->refCount, -1) == 1)
            delete value;
    }
}
