// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: HandleRefPtr227dc0::~HandleRefPtr227dc0, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HandleObj227dc0, HandleRefPtr227dc0, HandleEntry227dc0, DeleteThis, refCount, object, handleBits, target: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class HandleObj227dc0
{
public:
    virtual ~HandleObj227dc0();
    virtual void DeleteThis();

    long refCount;  // 08
};

class HandleRefPtr227dc0
{
public:
    ~HandleRefPtr227dc0()
    {
        HandleObj227dc0* obj = object;
        if (obj)
        {
            // Atomic reference count decrement using the 10-bit reference count mask.
            long next = _InterlockedExchangeAdd(&obj->refCount, -1) - 1;
            if ((next & 0x3FF) == 0)
            {
                obj->DeleteThis();
            }
        }
    }

    HandleObj227dc0* object;  // 00
};

class HandleEntry227dc0
{
public:
    ~HandleEntry227dc0();

    std::uint64_t handleBits;   // 00
    HandleRefPtr227dc0 target;  // 08
};
