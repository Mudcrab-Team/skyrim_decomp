// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f8130::~SmartPtr2f8130, RefObj2f8130::Release and Array2f8130::~Array2f8130, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount and BSTArray::~BSTArray (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, include/RE/B/BSTArray.h:427, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefObj2f8130, SmartPtr2f8130, AllocBase2f8130, ArrayBase2f8130, Array2f8130, Obj2f8130: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class RefObj2f8130
{
public:
    virtual ~RefObj2f8130();
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

class SmartPtr2f8130
{
public:
    ~SmartPtr2f8130()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    RefObj2f8130* m_ptr;  // 0x00
};

struct AllocBase2f8130
{
    ~AllocBase2f8130();
    void Deallocate();

    void* m_data;         // 0x00
    std::uint64_t unk08;  // 0x08
};

struct ArrayBase2f8130
{
    ~ArrayBase2f8130();

    std::uint32_t m_size;  // 0x00
};

struct Array2f8130 : public AllocBase2f8130, public ArrayBase2f8130
{
    ~Array2f8130()
    {
        if (m_data)
        {
            Deallocate();
            m_size = 0;
        }
    }
};
static_assert(sizeof(Array2f8130) == 0x18, "Array2f8130 size");

class Obj2f8130
{
public:
    ~Obj2f8130();

    Array2f8130 m_array;   // 0x00
    SmartPtr2f8130 m_ref;  // 0x18
};
