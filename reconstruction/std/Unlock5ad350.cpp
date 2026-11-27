// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock5ad350: GUESS(low) STANDIN; original owner is unknown
// Function5ad350: GUESS(low); provisional entry name
// 0x5ad350 Unlock5ad350::Function5ad350
#include "Unlock5ad350.h"

void Unlock5ad350::Function5ad350()
{
    if (callable) {
        callable->Destroy(callable != reinterpret_cast<Callable5ad350*>(this));
        callable = nullptr;
    }
}
