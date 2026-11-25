// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock11b6ae0: GUESS(low) STANDIN; original owner is unknown
// Function11b6ae0: GUESS(low); provisional entry name
// 0x11b6ae0 Unlock11b6ae0::Function11b6ae0
#include "Unlock11b6ae0.h"

Path11b6ae0* Unlock11b6ae0::Function11b6ae0(Path11b6ae0* out, const Path11b6ae0* source)
{
    out->x = source->x; out->y = source->y; out->z = source->z;
    out->first = source->first; out->second = source->second;
    out->flags = source->flags; out->byte2a = source->byte2a;
    auto* value = source->owner; auto* old = out->owner;
    if (value != old) {
        if (value) {
            // The copied owner crosses worker boundaries.
            _InterlockedIncrement(&value->references);
        }
        out->owner = value;
        if (old) {
            // Release shared ownership after publishing the replacement.
            if (_InterlockedExchangeAdd(&old->references, -1) == 1) delete old;
        }
    }
    out->byte2b = source->byte2b;
    return out;
}
