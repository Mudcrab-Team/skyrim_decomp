// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit201ce0::Clear201ce0 and IntrusivePtr201ce0::~IntrusivePtr201ce0, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Target201ce0, IntrusivePtr201ce0, Entry201ce0, Unit201ce0, DeleteThis, refCount, ptr, unk00, target, unk30, data, unk08, count, Deallocate, Clear201ce0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct Target201ce0
{
    virtual ~Target201ce0();
    virtual void DeleteThis();

    long refCount;  // 08
};
static_assert(offsetof(Target201ce0, refCount) == 0x08, "Target201ce0::refCount offset");

struct IntrusivePtr201ce0
{
    Target201ce0* ptr;  // 00

    ~IntrusivePtr201ce0()
    {
        Target201ce0* old = ptr;
        if (old) {
            // Atomic intrusive reference count decrement.
            const long count = _InterlockedDecrement(&old->refCount);
            if (count == 0) {
                old->DeleteThis();
            }
        }
    }
};

struct Entry201ce0
{
    std::uint8_t unk00[0x28];  // 00
    IntrusivePtr201ce0 target; // 28
    std::uint8_t unk30[0x98];  // 30
};
static_assert(sizeof(Entry201ce0) == 0xC8, "Entry201ce0 size");
static_assert(offsetof(Entry201ce0, target) == 0x28, "Entry201ce0::target offset");

struct Unit201ce0
{
    Entry201ce0** data;  // 00
    std::uint64_t unk08; // 08
    std::uint32_t count; // 10

    void Deallocate();
    void Clear201ce0(bool a_deallocate);  // compared: 0x201ce0
};
static_assert(offsetof(Unit201ce0, count) == 0x10, "Unit201ce0::count offset");
