// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock11b6600: GUESS(low) STANDIN; original owner is unknown
// Function11b6600: GUESS(low); provisional entry name
// 0x11b6600 Unlock11b6600::Function11b6600
#include "Unlock11b6600.h"

Path11b6600* Unlock11b6600::Function11b6600(Path11b6600* out, const Path11b6600* source)
{
    out->x = source->x; out->y = source->y; out->z = source->z;
    out->first = source->first; out->second = source->second;
    out->owner = source->owner;
    if (source->owner) {
        // The new path retains a shared owner.
        _InterlockedIncrement(&source->owner->references);
    }
    out->flags = source->flags; out->byte2a = source->byte2a;
    out->byte2b = source->byte2b;
    return out;
}
