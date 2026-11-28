// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2dc530::operator=, RefObj2dc530::IncRef and DecRef, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2dc530, SmartPtr2dc530, Obj2dc530: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class RefObj2dc530
{
public:
    virtual ~RefObj2dc530();
    virtual void DeleteThis();

    void IncRef()
    {
        // Atomic refcount increment on intrusive refcounted object.
        _InterlockedIncrement(&m_refCount);
    }

    void DecRef()
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

class SmartPtr2dc530
{
public:
    SmartPtr2dc530& operator=(const SmartPtr2dc530& a_rhs)
    {
        RefObj2dc530* oldPtr = m_ptr;
        RefObj2dc530* newPtr = a_rhs.m_ptr;
        if (oldPtr != newPtr)
        {
            if (newPtr)
            {
                newPtr->IncRef();
            }
            m_ptr = newPtr;
            if (oldPtr)
            {
                oldPtr->DecRef();
            }
        }
        return *this;
    }

    RefObj2dc530* m_ptr;  // 0x00
};

class Obj2dc530
{
public:
    Obj2dc530& operator=(const Obj2dc530& a_rhs);

    SmartPtr2dc530 m_first;   // 0x00
    SmartPtr2dc530 m_second;  // 0x08
    SmartPtr2dc530 m_third;   // 0x10
    std::uint8_t m_flag;      // 0x18
};
