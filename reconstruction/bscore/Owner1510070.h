// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0xce8530 (bscore/MemoryHeap): source copied, names replaced by placeholders.
// Origin: target listing and anonymous sibling hints.
// Function1510070, Owner1510070: GUESS(low) STANDIN
// BaseAllocate, BaseFree, Allocate, Size, TotalSize: GUESS(low) STANDIN
#pragma once
#include "MemoryHeap.h"

class Owner1510070 {
public:
    void* BaseAllocate(std::uint64_t, std::uint64_t, bool);
    void BaseFree(void*);
    void* Allocate(std::uint64_t, unsigned int);
    void Function1510070(void*, unsigned int);
    std::uint64_t Size(const void*) const;
    std::uint64_t TotalSize(const void*) const;
};

