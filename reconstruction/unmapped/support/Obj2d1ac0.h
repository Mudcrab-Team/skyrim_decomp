// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2d1ac0::~SmartPtr2d1ac0 and RefCounted2d1ac0::Release, treated as adapted: shaped like NiPointer::~NiPointer and BSHandleRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/B/BSHandleRefObject.cpp:12, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefCounted2d1ac0, Prefix2d1ac0, Pointee2d1ac0, SmartPtr2d1ac0, Obj2d1ac0: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class Prefix2d1ac0
{
public:
    virtual ~Prefix2d1ac0();

    std::uint64_t m_unk08;  // 0x08
    std::uint64_t m_unk10;  // 0x10
    std::uint64_t m_unk18;  // 0x18
};
static_assert(sizeof(Prefix2d1ac0) == 0x20, "Prefix2d1ac0 size");

class RefCounted2d1ac0
{
public:
    virtual ~RefCounted2d1ac0();
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

class Pointee2d1ac0 : public Prefix2d1ac0, public RefCounted2d1ac0
{
};

template <class T>
class SmartPtr2d1ac0
{
public:
    ~SmartPtr2d1ac0()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    T* m_ptr;  // 0x00
};

class Obj2d1ac0
{
public:
    ~Obj2d1ac0();

    std::uint64_t m_unk00;                // 0x00
    SmartPtr2d1ac0<Pointee2d1ac0> m_ref;  // 0x08
};
