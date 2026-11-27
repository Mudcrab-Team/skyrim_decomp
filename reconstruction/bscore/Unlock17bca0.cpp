// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock17bca0: GUESS(low) STANDIN; original owner is unknown
// Function17bca0: GUESS(low); provisional entry name
// 0x17bca0 Unlock17bca0::~Unlock17bca0
#include "Unlock17bca0.h"

Unlock17bca0::~Unlock17bca0()
{
    if (pointer)
        pointer->Release();
}
