// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2dc4a0::~SmartPtr2dc4a0 and RefObj2dc4a0::Release, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2dc4a0, SmartPtr2dc4a0, Obj2dc4a0: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class RefObj2dc4a0
{
public:
    virtual ~RefObj2dc4a0();
    virtual void DeleteThis();

    void Release()
    {
        // Atomic refcount release on intrusive refcounted object.
        const long count = _InterlockedDecrement(&m_refCount);
        if (count == 0)
        {
            DeleteThis();
        }
    }

    long m_refCount;  // 0x08
};

class SmartPtr2dc4a0
{
public:
    ~SmartPtr2dc4a0()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    RefObj2dc4a0* m_ptr;  // 0x00
};

class Obj2dc4a0
{
public:
    ~Obj2dc4a0();

    SmartPtr2dc4a0 m_first;   // 0x00
    SmartPtr2dc4a0 m_second;  // 0x08
    SmartPtr2dc4a0 m_third;   // 0x10
};
