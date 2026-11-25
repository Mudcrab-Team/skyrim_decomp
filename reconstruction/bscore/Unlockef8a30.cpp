// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockef8a30: GUESS(low) STANDIN; original owner is unknown
// Functionef8a30: GUESS(low); provisional entry name
// 0xef8a30 Unlockef8a30::Functionef8a30
#include "Unlockef8a30.h"

Valueef8a30* Unlockef8a30::Functionef8a30(Valueef8a30* out, float x, float y, float z, float w)
{
    out->w = w; out->x = x; out->y = y; out->z = z;
    return out;
}
