// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit202140::~Unit202140 and IntrusivePtr202140::~IntrusivePtr202140, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target202140, IntrusivePtr202140, ArrayAllocator202140, ArrayHeader202140, Unit202140, DeleteThis, refCount, ptr, data, unk08, Deallocate, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target202140
{
    virtual ~Target202140();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target202140, refCount) == 0x08, "Target202140::refCount offset");

struct IntrusivePtr202140
{
    Target202140* ptr;  // 00

    ~IntrusivePtr202140()
    {
        Target202140* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct ArrayAllocator202140
{
    IntrusivePtr202140* data;  // 00
    std::uint64_t unk08;       // 08

    ~ArrayAllocator202140();
    void Deallocate();
};
static_assert(sizeof(ArrayAllocator202140) == 0x10, "ArrayAllocator202140 size");

struct ArrayHeader202140
{
    std::uint32_t count;  // 00

    ~ArrayHeader202140();
};

struct Unit202140 : ArrayAllocator202140, ArrayHeader202140
{
    ~Unit202140();  // compared: 0x202140
};
static_assert(offsetof(Unit202140, count) == 0x10, "Unit202140::count offset");
