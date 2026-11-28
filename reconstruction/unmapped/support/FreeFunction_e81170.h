// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// AllocDesc_e81170, Heap_e81170, PagedArray_e81170, g_heap_e81170, Functione81170, Slot0, Slot1, Slot2, Slot3, Slot4, Slot5, Slot6, Slot7, Slot8, Slot9, Slot10, Realloc, Slot12, Slot13, AllocAutoHeap, id, unk00, pageCount, capacity, pages, ptr, bytes, owner, desc, array, index: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct AllocDesc_e81170
{
    std::uint32_t id;  // 0x00
};

struct Heap_e81170
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void* Realloc(void* ptr, std::size_t bytes);
    virtual void Slot12();
    virtual void Slot13();
    virtual void* AllocAutoHeap(const void* owner, std::size_t bytes, const AllocDesc_e81170* desc);
};

extern Heap_e81170* g_heap_e81170;

struct PagedArray_e81170
{
    std::uint64_t unk00;     // 0x00
    std::size_t pageCount;   // 0x08
    std::size_t capacity;    // 0x10
    void** pages;            // 0x18
};
static_assert(offsetof(PagedArray_e81170, pageCount) == 0x08, "pageCount offset");
static_assert(offsetof(PagedArray_e81170, capacity) == 0x10, "capacity offset");
static_assert(offsetof(PagedArray_e81170, pages) == 0x18, "pages offset");

void Functione81170(PagedArray_e81170* array, std::size_t index);
