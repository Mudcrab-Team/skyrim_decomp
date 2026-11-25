// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock10104f0: GUESS(low) STANDIN; original owner is unknown
// Function10104f0: GUESS(low); provisional entry name
// 0x10104f0 Unlock10104f0::Function10104f0
#include "Unlock10104f0.h"

void** Unlock10104f0::Function10104f0(void*, void*, void** out, std::uint32_t kind)
{
    void* resource;
    if (kind != 7) { resource = resources[resourceIndex]; resourceIndex = (resourceIndex + 1) & 3; }
    else resource = fallbackResource;
    Mapped10104f0 mapped; currentResource = resource;
    context->Map(resource, 0, 4, 0, &mapped);
    *out = mapped.data;
    return &currentResource;
}
