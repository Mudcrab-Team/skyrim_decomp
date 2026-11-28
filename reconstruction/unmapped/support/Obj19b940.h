// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj19b940::Assign, RefTarget19b940::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget19b940, Obj19b940, Assign: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefTarget19b940
{
    virtual ~RefTarget19b940();
    virtual void DeleteThis();

    void IncRef()
    {
        // atomic intrusive reference count increment
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // atomic intrusive reference count decrement
        if (_InterlockedDecrement(&refCount) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

struct Obj19b940
{
    Obj19b940& Assign(RefTarget19b940* a_rhs);  // compared: 0x19b940

    RefTarget19b940* ptr;  // 00
};
