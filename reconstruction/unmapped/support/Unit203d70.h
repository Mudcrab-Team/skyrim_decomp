// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr203d70::~IntrusivePtr203d70, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target203d70, IntrusivePtr203d70, Iterator203d70, ArrayHeader203d70, Unit203d70, DeleteThis, refCount, ptr, count, MoveTail, data, unk08, header, EraseUnordered203d70: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target203d70
{
    virtual ~Target203d70();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target203d70, refCount) == 0x08, "Target203d70::refCount offset");

struct IntrusivePtr203d70
{
    Target203d70* ptr;  // 00

    ~IntrusivePtr203d70()
    {
        Target203d70* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct Iterator203d70
{
    IntrusivePtr203d70* ptr;  // 00

    explicit Iterator203d70(IntrusivePtr203d70* a_ptr) : ptr(a_ptr) {}
};

// guess: the CrashLogger PDB names the MoveTail call BSTArray::RemoveElements; the stand-in name is kept.
struct ArrayHeader203d70
{
    std::uint32_t count;  // 00

    void MoveTail(void* a_data, std::uint32_t a_dst, std::uint32_t a_src, std::uint32_t a_num, std::uint32_t a_elemSize);
};

struct Unit203d70
{
    IntrusivePtr203d70* data;  // 00
    std::uint64_t unk08;       // 08
    ArrayHeader203d70 header;  // 10

    Iterator203d70 EraseUnordered203d70(const Iterator203d70& a_it);  // compared: 0x203d70
};
static_assert(offsetof(Unit203d70, header) == 0x10, "Unit203d70::header offset");
