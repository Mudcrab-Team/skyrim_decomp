// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2a8c00::Function2a8c00, RefObject2a8c00::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObject2a8c00, Obj2a8c00, Obj2a8c00::Function2a8c00: GUESS(low)
#pragma once

#include <cstddef>
#include <intrin.h>

class RefObject2a8c00
{
public:
    virtual ~RefObject2a8c00();
    virtual void DeleteThis();

    void IncRef()
    {
        // thread-safe reference count increment
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // thread-safe reference count decrement
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }

    long refCount;  // 0x08
};

class Obj2a8c00
{
public:
    Obj2a8c00& Function2a8c00(RefObject2a8c00* a_rhs);

    RefObject2a8c00* ptr;  // 0x00
};

static_assert(offsetof(RefObject2a8c00, refCount) == 0x08, "refCount offset");
