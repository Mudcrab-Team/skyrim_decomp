// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr18ff30::Reset and RefTarget18ff30::DecRef, treated as adapted: shaped like NiPointer::TryDetach and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:182, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget18ff30, SmartPtr18ff30, Obj18ff30, Reset: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefTarget18ff30
{
    virtual ~RefTarget18ff30();
    virtual void DeleteThis();

    void DecRef()
    {
        // atomic intrusive reference count decrement
        long count = _InterlockedDecrement(&refCount);
        if (count == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

struct SmartPtr18ff30
{
    void Reset()
    {
        if (ptr) {
            RefTarget18ff30* old = ptr;
            ptr = 0;
            old->DecRef();
        }
    }

    RefTarget18ff30* ptr;  // 00
};

struct Obj18ff30
{
    void Reset();  // compared: 0x18ff30

    SmartPtr18ff30 target;  // 00
    std::uint64_t unk08;    // 08
    std::uint64_t unk10;    // 10
};
