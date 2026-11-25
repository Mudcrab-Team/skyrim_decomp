// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockee5390: GUESS(low) STANDIN; original owner is unknown
// Functionee5390: GUESS(low); provisional entry name
// 0xee5390 Unlockee5390::Functionee5390
#include "Unlockee5390.h"

void* Unlockee5390::Functionee5390()
{
    auto index = nextLink++;
    auto link = streamLinks->links[index];
    return link == 0xffffffff ? nullptr : objects[link];
}
