// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: PtrA19b4c0 and PtrB19b4c0 destructors and the DecRef helpers, treated as adapted: shaped like NiPointer::~NiPointer and BSTSmartPointerIntrusiveRefCount::Release and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, include/RE/B/BSTSmartPointer.h:13, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObjA19b4c0, RefBaseB19b4c0, TargetB19b4c0, PtrA19b4c0, PtrB19b4c0, Obj19b4c0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefObjA19b4c0
{
    virtual ~RefObjA19b4c0();

    long DecRef()
    {
        // atomic intrusive reference count decrement
        return _InterlockedDecrement(&refCount);
    }

    long refCount;  // 08
};

struct RefBaseB19b4c0
{
    virtual ~RefBaseB19b4c0();
    virtual void DeleteThis();

    void DecRef()
    {
        // atomic intrusive reference count decrement
        if ((_InterlockedDecrement(&refCount) & 0x3FF) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

struct TargetB19b4c0
{
    std::uint64_t unk00[4];  // 00
    RefBaseB19b4c0 refBase;  // 20
};

struct PtrA19b4c0
{
    ~PtrA19b4c0()
    {
        RefObjA19b4c0* old = ptr;
        if (old) {
            long count = old->DecRef();
            if (count == 0) {
                delete old;
            }
        }
    }

    RefObjA19b4c0* ptr;  // 00
};

struct PtrB19b4c0
{
    ~PtrB19b4c0()
    {
        if (ptr) {
            ptr->refBase.DecRef();
        }
    }

    TargetB19b4c0* ptr;  // 00
};

struct Obj19b4c0
{
    ~Obj19b4c0();  // compared: 0x19b4c0

    std::uint64_t unk00;  // 00
    PtrB19b4c0 ptrB;      // 08
    PtrA19b4c0 ptrA;      // 10
};
