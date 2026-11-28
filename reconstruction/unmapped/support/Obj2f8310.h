// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f8310::~SmartPtr2f8310 and RefCounted2f8310::Release, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefCounted2f8310, Prefix2f8310, Pointee2f8310, SmartPtr2f8310, Obj2f8310: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class Prefix2f8310
{
public:
    virtual ~Prefix2f8310();

    std::uint64_t m_unk08;  // 0x08
    std::uint64_t m_unk10;  // 0x10
    std::uint64_t m_unk18;  // 0x18
};
static_assert(sizeof(Prefix2f8310) == 0x20, "Prefix2f8310 size");

class RefCounted2f8310
{
public:
    virtual ~RefCounted2f8310();
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

class Pointee2f8310 : public Prefix2f8310, public RefCounted2f8310
{
};

template <class T>
class SmartPtr2f8310
{
public:
    ~SmartPtr2f8310()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    T* m_ptr;  // 0x00
};

class Obj2f8310
{
public:
    ~Obj2f8310();

    SmartPtr2f8310<Pointee2f8310> m_ref;  // 0x00
};
