// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xe2bf20
// Adapted bodies: none.
// PagedPoolAllocatorE2bf20, gPagedPoolAllocatorE2bf20, PagedPoolE2bf20: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class PagedPoolAllocatorE2bf20 {
public:
    virtual ~PagedPoolAllocatorE2bf20();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void* Reallocate(void* a_block, std::size_t a_bytes);
    virtual void Slot12();
    virtual void Slot13();
    virtual void* Allocate(void* a_owner, std::size_t a_bytes, std::uint32_t* a_tag);
};

extern PagedPoolAllocatorE2bf20* gPagedPoolAllocatorE2bf20;

struct PagedPoolE2bf20 {
    std::uint64_t reserved00;
    std::size_t pageCount;
    std::size_t pageCapacity;
    void** pages;

    void AllocatePage(std::size_t a_pageIndex);
};
