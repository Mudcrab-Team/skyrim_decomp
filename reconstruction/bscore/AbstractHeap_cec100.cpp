// Source exposure: mixed (community-generated layout and local binary analysis).
// Code origin: original reconstruction from the assigned local pack; no adapted body.
// AbstractHeap: CRASHLOGGER_PDB(59818@2026.10.24)
// HeapStatistics, GetMemoryStatistics: GUESS(low); inferred statistics operation.
// 0xcec100 AbstractHeap::GetMemoryStatistics
#include "AbstractHeap_cec100.h"
void AbstractHeap::GetMemoryStatistics(HeapStatistics* stats) const
{
    stats->heapName = name;
    stats->allocated = memAllocated;
    stats->committed = currentSize;
    stats->reserved = initialSize;
    stats->overhead = static_cast<std::int64_t>(numBlocks) * 32 + 0x2a8;
    stats->free = currentSize - blockMemAllocated;
}
