// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17e7e0::~RefPtr17e7e0 and RefTarget17e7e0::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget17e7e0: GUESS(low)
// RefPtr17e7e0: GUESS(low)
// Entry17e7e0: GUESS(low)
// Func_17e7e0: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct RefTarget17e7e0
{
    virtual ~RefTarget17e7e0();
    virtual void DeleteThis();

    void DecRef()
    {
        // Atomic intrusive reference count decrement.
        if (_InterlockedDecrement(&refCount) == 0)
        {
            DeleteThis();
        }
    }

    long refCount;
};

struct RefPtr17e7e0
{
    ~RefPtr17e7e0()
    {
        if (ptr != nullptr)
        {
            ptr->DecRef();
        }
    }

    RefTarget17e7e0* ptr;
};

struct Entry17e7e0
{
    RefPtr17e7e0 target;
    std::uint64_t unk08;
    std::uint64_t unk10;
};

static_assert(sizeof(Entry17e7e0) == 0x18, "Entry17e7e0 size");

struct Func_17e7e0
{
    void DestroyRange(std::uint32_t startIndex, std::uint32_t count);

    Entry17e7e0* data;
};
