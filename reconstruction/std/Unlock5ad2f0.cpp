// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock5ad2f0: GUESS(low) STANDIN; original owner is unknown
// Function5ad2f0: GUESS(low); provisional entry name
// 0x5ad2f0 Unlock5ad2f0::Function5ad2f0
#include "Unlock5ad2f0.h"

void Unlock5ad2f0::Function5ad2f0()
{
    if (callable) {
        callable->Destroy(callable != reinterpret_cast<Callable5ad2f0*>(this));
        callable = nullptr;
    }
}
