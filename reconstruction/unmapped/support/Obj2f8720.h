// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2f8720::operator= and RefObj2f8720::Release, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2f8720, Obj2f8720: GUESS(low)
#pragma once

#include <intrin.h>

class RefObj2f8720
{
public:
    virtual ~RefObj2f8720();
    virtual void DeleteThis();

    void Release()
    {
        // Atomic refcount release on intrusive refcounted object.
        if (_InterlockedDecrement(&m_refCount) == 0)
        {
            DeleteThis();
        }
    }

    long m_refCount;  // 0x08
};

class Obj2f8720
{
public:
    Obj2f8720& operator=(RefObj2f8720* a_rhs);

    RefObj2f8720* m_ptr;  // 0x00
};
