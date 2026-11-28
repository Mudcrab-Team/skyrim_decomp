// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit20aaa0::~Unit20aaa0 and IntrusivePtr20aaa0::~IntrusivePtr20aaa0, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target20aaa0, IntrusivePtr20aaa0, ArrayAllocator20aaa0, ArrayHeader20aaa0, Unit20aaa0, DeleteThis, refCount, ptr, data, unk08, Deallocate, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target20aaa0
{
    virtual ~Target20aaa0();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target20aaa0, refCount) == 0x08, "Target20aaa0::refCount offset");

struct IntrusivePtr20aaa0
{
    Target20aaa0* ptr;  // 00

    ~IntrusivePtr20aaa0()
    {
        Target20aaa0* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct ArrayAllocator20aaa0
{
    IntrusivePtr20aaa0* data;  // 00
    std::uint64_t unk08;       // 08

    ~ArrayAllocator20aaa0();
    void Deallocate();
};
static_assert(sizeof(ArrayAllocator20aaa0) == 0x10, "ArrayAllocator20aaa0 size");

struct ArrayHeader20aaa0
{
    std::uint32_t count;  // 00

    ~ArrayHeader20aaa0();
};

struct Unit20aaa0 : ArrayAllocator20aaa0, ArrayHeader20aaa0
{
    ~Unit20aaa0();  // compared: 0x20aaa0
};
static_assert(offsetof(Unit20aaa0, count) == 0x10, "Unit20aaa0::count offset");
