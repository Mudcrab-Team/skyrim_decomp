// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock17b5b0: GUESS(low) STANDIN; original owner is unknown
// Function17b5b0: GUESS(low); provisional entry name
// 0x17b5b0 Unlock17b5b0::~Unlock17b5b0
#include "Unlock17b5b0.h"

Unlock17b5b0::~Unlock17b5b0()
{
    if (pointer)
        ReleaseReference(pointer);
}
