// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock5fc090: GUESS(low) STANDIN; original owner is unknown
// Function5fc090: GUESS(low); provisional entry name
// 0x5fc090 Unlock5fc090::Function5fc090
#include "Unlock5fc090.h"

void Unlock5fc090::Function5fc090()
{
    if (callable) {
        callable->Destroy(callable != reinterpret_cast<Callable5fc090*>(this));
        callable = nullptr;
    }
}
