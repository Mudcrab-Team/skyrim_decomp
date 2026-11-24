// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1d84c0 BGSIdleCollection::~BGSIdleCollection
// Adapted bodies: BGSIdleCollection::~BGSIdleCollection follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsidlecollection.cpp:182
#include "BGSIdleCollection_1d84c0.h"

inline BaseFormComponent::~BaseFormComponent() {}

BGSIdleCollection::BGSIdleCollection() = default;

namespace
{
// ReclaimIdleStorage: GUESS(low); the initialized heap owns the idle-pointer array.
inline void ReclaimIdleStorage(void* idleArray) noexcept
{
    if (g_memoryManagerGuard != 2)
        g_memoryManager.EnsureInit(&g_memoryManagerGuard);
    g_memoryManager.Deallocate(idleArray, false);
}
}

inline void BGSIdleCollection::Free()
{
    AllocationContextScope context(101);
    ReclaimIdleStorage(idles);
    idleCount = 0;
    idles = nullptr;
}

BGSIdleCollection::~BGSIdleCollection()
{
    BGSIdleCollection::Free();
}
