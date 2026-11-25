// Source exposure: binary-analysis
// Unlockce48c0: GUESS(low) STANDIN; original owner is unknown
// Functionce48c0: GUESS(low); provisional entry name
// 0xce48c0 Unlockce48c0::Functionce48c0
#include "Unlockce48c0.h"

void Unlockce48c0::Functionce48c0()
{
    if (pointer) {
        // References are shared between workers.
        _InterlockedDecrement(&pointer->references);
    }
}
