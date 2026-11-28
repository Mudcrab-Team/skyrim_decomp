// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f7e70::~SmartPtr2f7e70, RefObj2f7e70::Release and Obj2f7e70::~Obj2f7e70, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2f7e70, SmartPtr2f7e70, AllocBase2f7e70, ArrayBase2f7e70, Obj2f7e70: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class RefObj2f7e70
{
public:
    virtual ~RefObj2f7e70();
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

class SmartPtr2f7e70
{
public:
    ~SmartPtr2f7e70()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    RefObj2f7e70* m_ptr;  // 0x00
};

struct AllocBase2f7e70
{
    ~AllocBase2f7e70();
    void Deallocate();

    SmartPtr2f7e70* m_data;  // 0x00
    std::uint64_t unk08;     // 0x08
};

struct ArrayBase2f7e70
{
    ~ArrayBase2f7e70();

    std::uint32_t m_size;  // 0x00
};

class Obj2f7e70 : public AllocBase2f7e70, public ArrayBase2f7e70
{
public:
    ~Obj2f7e70();
};
