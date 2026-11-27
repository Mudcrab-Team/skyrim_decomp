// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock119a80: GUESS(low) STANDIN; original owner is unknown
// Function119a80: GUESS(low); provisional entry name
// 0x119a80 Unlock119a80::Function119a80
#include "Unlock119a80.h"

void Unlock119a80::Function119a80()
{
    if (callable) {
        callable->Destroy(callable != reinterpret_cast<Callable119a80*>(this));
        callable = nullptr;
    }
}
