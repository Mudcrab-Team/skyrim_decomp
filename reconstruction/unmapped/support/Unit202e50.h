// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr202e50::~IntrusivePtr202e50, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target202e50, IntrusivePtr202e50, Iterator202e50, ArrayHeader202e50, Unit202e50, DeleteThis, refCount, ptr, count, MoveTail, data, unk08, header, EraseUnordered202e50: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target202e50
{
    virtual ~Target202e50();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target202e50, refCount) == 0x08, "Target202e50::refCount offset");

struct IntrusivePtr202e50
{
    Target202e50* ptr;  // 00

    ~IntrusivePtr202e50()
    {
        Target202e50* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct Iterator202e50
{
    IntrusivePtr202e50* ptr;  // 00

    explicit Iterator202e50(IntrusivePtr202e50* a_ptr) : ptr(a_ptr) {}
};

// guess: the CrashLogger PDB names the MoveTail call BSTArray::RemoveElements; the stand-in name is kept.
struct ArrayHeader202e50
{
    std::uint32_t count;  // 00

    void MoveTail(void* a_data, std::uint32_t a_dst, std::uint32_t a_src, std::uint32_t a_num, std::uint32_t a_elemSize);
};

struct Unit202e50
{
    IntrusivePtr202e50* data;  // 00
    std::uint64_t unk08;       // 08
    ArrayHeader202e50 header;  // 10

    Iterator202e50 EraseUnordered202e50(const Iterator202e50& a_it);  // compared: 0x202e50
};
static_assert(offsetof(Unit202e50, header) == 0x10, "Unit202e50::header offset");
