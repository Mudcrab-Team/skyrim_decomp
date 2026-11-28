// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Allocator_eacd60, AllocatorHolder_eacd60, g_allocatorHolder_eacd60, Functioneacd60, Slot0, Slot1, Slot2, Slot3, Slot4, Free, allocator, ptr, alignment, size: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Allocator_eacd60
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Free(void* ptr, std::uint32_t alignment, std::size_t size);
};

struct AllocatorHolder_eacd60
{
    Allocator_eacd60* allocator;  // 0x00
};

extern AllocatorHolder_eacd60* g_allocatorHolder_eacd60;

void Functioneacd60(void* ptr);
