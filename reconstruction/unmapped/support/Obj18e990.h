// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr18e990::~SmartPtr18e990 and RefBase18e990::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefBase18e990, Target18e990, SmartPtr18e990, Obj18e990, DecRef: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefBase18e990
{
    virtual ~RefBase18e990();
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

struct Target18e990
{
    std::uint64_t unk00[4];  // 00
    RefBase18e990 refBase;   // 20
};

struct SmartPtr18e990
{
    ~SmartPtr18e990()
    {
        if (ptr) {
            ptr->refBase.DecRef();
        }
    }

    Target18e990* ptr;  // 00
};

struct Obj18e990
{
    ~Obj18e990();  // compared: 0x18e990

    SmartPtr18e990 target;  // 00
};
