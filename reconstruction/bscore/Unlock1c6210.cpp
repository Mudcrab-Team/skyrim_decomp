// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1c6210: GUESS(low) STANDIN; original owner is unknown
// Function1c6210: GUESS(low); provisional entry name
// 0x1c6210 Unlock1c6210::Function1c6210
#include "Unlock1c6210.h"

void Unlock1c6210::Function1c6210()
{
    if (word) {
        *word = 0;
        // Release the protected owner before subsequent stores.
        _mm_mfence();
    }
}
