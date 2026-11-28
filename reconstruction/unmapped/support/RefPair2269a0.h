// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr2269a0::~RefPtr2269a0 and RefObj2269a0::DecRefCount, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2269a0, RefPtr2269a0, RefPair2269a0, DeleteThis, DecRefCount, refCount, object, first, second: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class RefObj2269a0
{
public:
    virtual ~RefObj2269a0();
    virtual void DeleteThis();

    void DecRefCount()
    {
        // Atomic reference count decrement for shared object ownership.
        std::uint32_t count = _InterlockedDecrement(&refCount);
        if (count == 0)
        {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

class RefPtr2269a0
{
public:
    ~RefPtr2269a0()
    {
        RefObj2269a0* obj = object;
        if (obj)
        {
            obj->DecRefCount();
        }
    }

    RefObj2269a0* object;  // 00
};

class RefPair2269a0
{
public:
    ~RefPair2269a0();

    RefPtr2269a0 first;   // 00
    RefPtr2269a0 second;  // 08
};
