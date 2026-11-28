// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GMemoryHeap, GMemoryHeap::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryHeapLock, unk08, lock, unkA0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

struct GMemoryHeapLock
{
    ~GMemoryHeapLock();

    std::uint64_t unk00;  // 00
};
static_assert(sizeof(GMemoryHeapLock) == 0x08, "GMemoryHeapLock size");

class GMemoryHeap
{
public:
    GMemoryHeap();
    virtual ~GMemoryHeap();  // compared: 0xcf8ed0

    std::uint8_t unk08[0x90];  // 08
    GMemoryHeapLock lock;  // 98
    std::uint8_t unkA0[0x28];  // A0
};
static_assert(offsetof(GMemoryHeap, lock) == 0x98, "lock offset");
static_assert(sizeof(GMemoryHeap) == 0xC8, "GMemoryHeap size");
