// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0xce8540 (bscore/MemoryHeap): source copied, names replaced by placeholders.
// Origin: target listing and anonymous sibling hints.
// Function10e24b0, Owner10e24b0: GUESS(low) STANDIN
// BaseAllocate, BaseFree, Allocate, Deallocate, TotalSize: GUESS(low) STANDIN
#pragma once
#include "MemoryHeap.h"

class Owner10e24b0 {
public:
    void* BaseAllocate(std::uint64_t, std::uint64_t, bool);
    void BaseFree(void*);
    void* Allocate(std::uint64_t, unsigned int);
    void Deallocate(void*, unsigned int);
    std::uint64_t Function10e24b0(const void*) const;
    std::uint64_t TotalSize(const void*) const;
};
