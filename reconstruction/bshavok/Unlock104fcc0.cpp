// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock104fcc0: GUESS(low) STANDIN; original owner is unknown
// Function104fcc0: GUESS(low); provisional entry name
// 0x104fcc0 Unlock104fcc0::Function104fcc0
#include "Unlock104fcc0.h"

void Unlock104fcc0::Function104fcc0()
{
    if (lockEnabled) UnlockRead(&worldLock);
}
