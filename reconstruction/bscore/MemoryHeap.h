// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// MemoryHeap, BaseAllocate, BaseFree, Allocate, Deallocate, Size, TotalSize: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>
class MemoryHeap {
public:
    void* BaseAllocate(std::uint64_t, std::uint64_t, bool);
    void BaseFree(void*);
    void* Allocate(std::uint64_t, unsigned int);
    void Deallocate(void*, unsigned int);
    std::uint64_t Size(const void*) const;
    std::uint64_t TotalSize(const void*) const;
};
