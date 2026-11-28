// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit205c50::~Unit205c50 and IntrusivePtr205c50::~IntrusivePtr205c50, treated as adapted: shaped like NiPointer::~NiPointer and BSTSmartPointerIntrusiveRefCount::Release and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, include/RE/B/BSTSmartPointer.h:13, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target205c50, IntrusivePtr205c50, ArrayAllocator205c50, ArrayHeader205c50, Unit205c50, refCount, ptr, data, unk08, Deallocate, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target205c50
{
    virtual ~Target205c50();

    long refCount;  // 08
};
static_assert(offsetof(Target205c50, refCount) == 0x08, "Target205c50::refCount offset");

struct IntrusivePtr205c50
{
    Target205c50* ptr;  // 00

    ~IntrusivePtr205c50()
    {
        Target205c50* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                delete old;
            }
        }
    }
};

struct ArrayAllocator205c50
{
    IntrusivePtr205c50* data;  // 00
    std::uint64_t unk08;       // 08

    ~ArrayAllocator205c50();
    void Deallocate();
};
static_assert(sizeof(ArrayAllocator205c50) == 0x10, "ArrayAllocator205c50 size");

struct ArrayHeader205c50
{
    std::uint32_t count;  // 00

    ~ArrayHeader205c50();
};

struct Unit205c50 : ArrayAllocator205c50, ArrayHeader205c50
{
    ~Unit205c50();  // compared: 0x205c50
};
static_assert(offsetof(Unit205c50, count) == 0x10, "Unit205c50::count offset");
