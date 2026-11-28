// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr17be10::operator=, RefCountBase17be10::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and BSHandleRefObject::DecRefCount and BSHandleRefObject::IncRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/B/BSHandleRefObject.cpp:12, src/RE/B/BSHandleRefObject.cpp:20, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PrimaryBase17be10: GUESS(low)
// RefCountBase17be10: GUESS(low)
// RefObject17be10: GUESS(low)
// SmartPtr17be10: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct PrimaryBase17be10
{
    virtual ~PrimaryBase17be10();
    std::uint64_t unk08[3];
};

static_assert(sizeof(PrimaryBase17be10) == 0x20, "PrimaryBase17be10 size");

struct RefCountBase17be10
{
    virtual ~RefCountBase17be10();
    virtual void DeleteThis();

    void IncRef()
    {
        // Atomic intrusive reference count increment.
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // Atomic intrusive reference count decrement with 10-bit count mask.
        if ((_InterlockedDecrement(&refCount) & 0x3FF) == 0)
        {
            DeleteThis();
        }
    }

    long refCount;
};

struct RefObject17be10 : PrimaryBase17be10, RefCountBase17be10
{
};

struct SmartPtr17be10
{
    SmartPtr17be10& operator=(RefObject17be10* rhs);

    RefObject17be10* ptr;
};
