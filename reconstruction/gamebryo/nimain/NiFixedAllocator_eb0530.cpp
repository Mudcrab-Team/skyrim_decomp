// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xeb0530 NiFixedAllocator::Reserve
#include "NiFixedAllocator_eb0530.h"

extern void* ResizeChunks(void*, std::size_t);

void NiFixedAllocator::Reserve(std::size_t requested)
{
    if (requested <= capacity) {
        return;
    }
    chunks = ResizeChunks(chunks, requested * 16);
    capacity = requested;
}
