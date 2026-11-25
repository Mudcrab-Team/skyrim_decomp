// Source exposure: mixed (community-generated layout and local binary analysis).
// Code origin: original reconstruction; member names from community-generated layout.
// AbstractHeap, name, initialSize, currentSize, memAllocated, memAllocatedHigh, blockMemAllocated, numBlocks: CRASHLOGGER_PDB(59818@2026.10.24)
// HeapStatistics, GetMemoryStatistics, heapName, allocated, committed, reserved, overhead, free: GUESS(low); local statistics stand-ins.
// 0xcec100 AbstractHeap::GetMemoryStatistics
#pragma once
#include <cstddef>
#include <cstdint>
struct HeapStatistics
{
    const char* heapName;
    std::uint64_t allocated;
    std::uint64_t committed;
    std::uint64_t reserved;
    std::uint64_t overhead;
    std::uint64_t free;
};
class AbstractHeap
{
public:
    void GetMemoryStatistics(HeapStatistics* stats) const;
    std::uint8_t unknown00[0x30];
    const char* name;
    std::uint8_t unknown38[0x10];
    std::uint32_t initialSize;
    std::uint8_t unknown4c[0xc];
    std::uint32_t currentSize;
    std::uint8_t unknown5c[0xc];
    std::uint32_t memAllocated;
    std::uint8_t unknown6c[0xc];
    std::uint32_t blockMemAllocated;
    std::uint8_t unknown7c[0xc];
    std::int32_t numBlocks;
};
static_assert(offsetof(AbstractHeap, name) == 0x30, "heap name offset");
static_assert(offsetof(AbstractHeap, initialSize) == 0x48, "initial size offset");
static_assert(offsetof(AbstractHeap, currentSize) == 0x58, "current size offset");
static_assert(offsetof(AbstractHeap, memAllocated) == 0x68, "allocated size offset");
static_assert(offsetof(AbstractHeap, blockMemAllocated) == 0x78, "block allocation offset");
static_assert(offsetof(AbstractHeap, numBlocks) == 0x88, "block count offset");
