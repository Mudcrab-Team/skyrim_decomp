// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit2038f0::~Unit2038f0 and IntrusivePtr2038f0::~IntrusivePtr2038f0, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target2038f0, IntrusivePtr2038f0, ArrayAllocator2038f0, ArrayHeader2038f0, Unit2038f0, DeleteThis, refCount, ptr, data, unk08, Deallocate, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target2038f0
{
    virtual ~Target2038f0();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target2038f0, refCount) == 0x08, "Target2038f0::refCount offset");

struct IntrusivePtr2038f0
{
    Target2038f0* ptr;  // 00

    ~IntrusivePtr2038f0()
    {
        Target2038f0* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct ArrayAllocator2038f0
{
    IntrusivePtr2038f0* data;  // 00
    std::uint64_t unk08;       // 08

    ~ArrayAllocator2038f0();
    void Deallocate();
};
static_assert(sizeof(ArrayAllocator2038f0) == 0x10, "ArrayAllocator2038f0 size");

struct ArrayHeader2038f0
{
    std::uint32_t count;  // 00

    ~ArrayHeader2038f0();
};

struct Unit2038f0 : ArrayAllocator2038f0, ArrayHeader2038f0
{
    ~Unit2038f0();  // compared: 0x2038f0
};
static_assert(offsetof(Unit2038f0, count) == 0x10, "Unit2038f0::count offset");
