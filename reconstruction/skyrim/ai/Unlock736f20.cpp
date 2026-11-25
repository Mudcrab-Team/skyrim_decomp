// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Unlock736f20: GUESS(low) STANDIN; original owner is unknown
// Function736f20: GUESS(low); provisional entry name
// 0x736f20 Unlock736f20::Function736f20
#include "Unlock736f20.h"

void Unlock736f20::Function736f20(void* buffer)
{
    ReadField(buffer, &start, 4, 4);
    ReadField(buffer, &duration, 4, 4);
    if (start < upperBound && start > lowerBound) start += timeDelta;
}
