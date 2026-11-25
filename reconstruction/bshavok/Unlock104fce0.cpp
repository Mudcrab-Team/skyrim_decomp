// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock104fce0: GUESS(low) STANDIN; original owner is unknown
// Function104fce0: GUESS(low); provisional entry name
// 0x104fce0 Unlock104fce0::Function104fce0
#include "Unlock104fce0.h"

void Unlock104fce0::Function104fce0()
{
    if (lockEnabled) LockWrite(&worldLock);
}
