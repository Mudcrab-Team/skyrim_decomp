// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xcddd10 MemoryManager::GetIMemoryHeap
#include "MemoryManager_cddd10.h"

// Returns the first registered heap that claims ownership of ptr, or null if none matches.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
IMemoryHeap* MemoryManager::GetIMemoryHeap(const void* ptr) const
{
    IMemoryHeap* result = nullptr;
    for (std::uint16_t i = 0; i < heapCount && !result; ++i)
    {
        IMemoryHeap* heap = heaps[i];
        if (heap->PointerInHeap(ptr))
        {
            result = heap;
        }
    }
    return result;
}
