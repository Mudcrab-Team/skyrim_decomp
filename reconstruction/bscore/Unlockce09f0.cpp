// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockce09f0: GUESS(low) STANDIN; original owner is unknown
// Functionce09f0: GUESS(low); provisional entry name
// 0xce09f0 Unlockce09f0::Functionce09f0
#include "Unlockce09f0.h"

bool Unlockce09f0::Functionce09f0(void*, Allocatorce09f0* allocator, std::uint32_t count, std::uint32_t stride)
{
    if (count) return allocator->Allocate(count, stride);
    return true;
}
