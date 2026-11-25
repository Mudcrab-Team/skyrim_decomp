// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1270b0: GUESS(low) STANDIN; original owner is unknown
// Function1270b0: GUESS(low); provisional entry name
// 0x1270b0 Unlock1270b0::Function1270b0
#include "Unlock1270b0.h"

void Unlock1270b0::Function1270b0()
{
    auto* value = pointer;
    if (value) {
        long observed = value->refCount;
        long expected, desired;
        do {
            expected = observed; desired = expected - 0x1000;
            // Preserve tag bits while dropping a shared reference.
            observed = _InterlockedCompareExchange(&value->refCount, desired, expected);
        } while (observed != expected);
        if (!(desired & 0xfffff000)) delete value;
    }
}
