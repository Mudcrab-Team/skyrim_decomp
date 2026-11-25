// Source exposure: binary-analysis
// Unlock104fca0: GUESS(low) STANDIN; original owner is unknown
// Function104fca0: GUESS(low); provisional entry name
// 0x104fca0 Unlock104fca0::Function104fca0
#include "Unlock104fca0.h"

void Unlock104fca0::Function104fca0()
{
    if (lockEnabled) LockRead(&worldLock);
}
