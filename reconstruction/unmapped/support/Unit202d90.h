// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IntrusivePtr202d90::~IntrusivePtr202d90, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target202d90, IntrusivePtr202d90, ArrayHeader202d90, Unit202d90, DeleteThis, refCount, ptr, count, MoveTail, data, unk08, header, EraseUnordered202d90: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target202d90
{
    virtual ~Target202d90();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target202d90, refCount) == 0x08, "Target202d90::refCount offset");

struct IntrusivePtr202d90
{
    Target202d90* ptr;  // 00

    ~IntrusivePtr202d90()
    {
        Target202d90* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

// guess: the CrashLogger PDB names the MoveTail call BSTArray::RemoveElements; the stand-in name is kept.
struct ArrayHeader202d90
{
    std::uint32_t count;  // 00

    void MoveTail(void* a_data, std::uint32_t a_dst, std::uint32_t a_src, std::uint32_t a_num, std::uint32_t a_elemSize);
};

struct Unit202d90
{
    IntrusivePtr202d90* data;  // 00
    std::uint64_t unk08;       // 08
    ArrayHeader202d90 header;  // 10

    void EraseUnordered202d90(std::uint32_t a_index, std::uint32_t a_count);  // compared: 0x202d90
};
static_assert(offsetof(Unit202d90, header) == 0x10, "Unit202d90::header offset");
