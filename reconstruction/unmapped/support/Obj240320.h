// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr240320::~RefPtr240320, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PrimaryBase240320, SecondaryRefBase240320, RefTarget240320, RefPtr240320, Obj240320, DeleteThis, refCount, object, target: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class PrimaryBase240320
{
public:
    virtual ~PrimaryBase240320();

    std::uint8_t unk08[0x18];  // 08
};

class SecondaryRefBase240320
{
public:
    virtual ~SecondaryRefBase240320();
    virtual void DeleteThis();

    long refCount;  // 08
};

class RefTarget240320 : public PrimaryBase240320, public SecondaryRefBase240320
{
};

class RefPtr240320
{
public:
    ~RefPtr240320()
    {
        RefTarget240320* obj = object;
        if (obj)
        {
            SecondaryRefBase240320* ref = obj;
            // Atomic reference count decrement using the 10-bit reference count mask.
            long next = _InterlockedExchangeAdd(&ref->refCount, -1) - 1;
            if ((next & 0x3FF) == 0)
            {
                ref->DeleteThis();
            }
        }
    }

    RefTarget240320* object;  // 00
};

class Obj240320
{
public:
    ~Obj240320();

    RefPtr240320 target;  // 00
};
