// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr222980::~RefPtr222980, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject222980, RefPtr222980, Allocator222980, ArrayBase222980, Array222980, DeleteThis, DecRefCount, Deallocate, refCount, reserved, ptr, data, capacity, unk0C, size: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct RefObject222980
{
    virtual ~RefObject222980();
    virtual void DeleteThis();

    long refCount;           // 0x08
    std::uint32_t reserved;  // 0x0C

    void DecRefCount()
    {
        // Reference count is decremented atomically across threads.
        std::uint32_t remaining = static_cast<std::uint32_t>(_InterlockedDecrement(&refCount));
        if (remaining == 0) {
            DeleteThis();
        }
    }
};
static_assert(sizeof(RefObject222980) == 0x10, "RefObject222980 size");

struct RefPtr222980
{
    RefObject222980* ptr;  // 0x00

    ~RefPtr222980()
    {
        if (ptr != nullptr) {
            ptr->DecRefCount();
        }
    }
};
static_assert(sizeof(RefPtr222980) == 0x8, "RefPtr222980 size");

struct Allocator222980
{
    ~Allocator222980();
    void Deallocate();

    RefPtr222980* data;      // 0x00
    std::uint32_t capacity;  // 0x08
    std::uint32_t unk0C;     // 0x0C
};
static_assert(sizeof(Allocator222980) == 0x10, "Allocator222980 size");

struct ArrayBase222980
{
    ~ArrayBase222980();

    std::uint32_t size;  // 0x00
};
static_assert(sizeof(ArrayBase222980) == 0x4, "ArrayBase222980 size");

struct Array222980 : Allocator222980
{
    ~Array222980();

    ArrayBase222980 base;  // 0x10
};
static_assert(sizeof(Array222980) == 0x18, "Array222980 size");
