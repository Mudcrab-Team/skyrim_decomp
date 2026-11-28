// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr3156b0::~SmartPtr3156b0, RefBase3156b0::Release and Obj3156b0::RemoveRange, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Prefix3156b0, RefBase3156b0, Target3156b0, SmartPtr3156b0, AllocBase3156b0, ArrayBase3156b0, Obj3156b0, Obj3156b0::RemoveRange: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class Prefix3156b0
{
public:
    virtual ~Prefix3156b0();

    std::uint64_t unk08[3];  // 0x08
};

class RefBase3156b0
{
public:
    virtual ~RefBase3156b0();
    virtual void DeleteThis();

    void Release()
    {
        // Atomic masked refcount release on intrusive refcounted object.
        const long count = _InterlockedDecrement(&m_refCount);
        if ((count & 0x3FF) == 0)
        {
            DeleteThis();
        }
    }

    long m_refCount;  // 0x08
};

class Target3156b0 : public Prefix3156b0, public RefBase3156b0
{
};

class SmartPtr3156b0
{
public:
    ~SmartPtr3156b0()
    {
        if (m_ptr)
        {
            static_cast<RefBase3156b0*>(m_ptr)->Release();
        }
    }

    Target3156b0* m_ptr;  // 0x00
};

struct AllocBase3156b0
{
    SmartPtr3156b0* m_data;  // 0x00
    std::uint64_t unk08;     // 0x08
};

struct ArrayBase3156b0
{
    void MoveElements(void* a_data, std::uint32_t a_dst, std::uint32_t a_src, std::uint32_t a_count, std::uint32_t a_elemSize);

    std::uint32_t m_size;  // 0x00
};

class Obj3156b0 : public AllocBase3156b0, public ArrayBase3156b0
{
public:
    void RemoveRange(std::uint32_t a_index, std::uint32_t a_count);
};
