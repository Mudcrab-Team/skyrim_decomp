// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f8240::~SmartPtr2f8240 and RefCounted2f8240::Release, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Prefix2f8240, RefCounted2f8240, Pointee2f8240, SmartPtr2f8240, Obj2f8240: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class Prefix2f8240
{
public:
    virtual ~Prefix2f8240();

    std::uint64_t unk08[3];  // 0x08
};
static_assert(sizeof(Prefix2f8240) == 0x20, "Prefix2f8240 size");

class RefCounted2f8240
{
public:
    virtual ~RefCounted2f8240();
    virtual void DeleteThis();

    void Release()
    {
        // Atomic refcount release on intrusive refcounted object.
        if ((_InterlockedDecrement(&m_refCount) & 0x3FF) == 0)
        {
            DeleteThis();
        }
    }

    long m_refCount;  // 0x08
};

class Pointee2f8240 : public Prefix2f8240, public RefCounted2f8240
{
};

template <class T>
class SmartPtr2f8240
{
public:
    ~SmartPtr2f8240()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    T* m_ptr;  // 0x00
};

class Obj2f8240
{
public:
    ~Obj2f8240();

    SmartPtr2f8240<Pointee2f8240> m_first;   // 0x00
    SmartPtr2f8240<Pointee2f8240> m_second;  // 0x08
};
