// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock104fd00: GUESS(low) STANDIN; original owner is unknown
// Function104fd00: GUESS(low); provisional entry name
// 0x104fd00 Unlock104fd00::Function104fd00
#include "Unlock104fd00.h"

void Unlock104fd00::Function104fd00()
{
    if (lockEnabled) UnlockWrite(&worldLock);
}
