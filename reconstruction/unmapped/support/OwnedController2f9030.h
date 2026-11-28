// Source exposure: mixed (pinned image listing; community source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f9030::~SmartPtr2f9030 and RefObj2f9030::Release, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// OwnedController2f9030: CRASHLOGGER_PDB(59818@2026.10.24)
// RefObj2f9030, SmartPtr2f9030, Base2f9030: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class RefObj2f9030
{
public:
    virtual ~RefObj2f9030();
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

class SmartPtr2f9030
{
public:
    ~SmartPtr2f9030()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    RefObj2f9030* m_ptr;  // 0x00
};

class Base2f9030
{
public:
    virtual ~Base2f9030();

    std::uint64_t unk08[4];  // 0x08
};
static_assert(sizeof(Base2f9030) == 0x28, "Base2f9030 size");

class OwnedController2f9030 : public Base2f9030
{
public:
    OwnedController2f9030();
    ~OwnedController2f9030() override = default;

    SmartPtr2f9030 m_owner;  // 0x28
};
static_assert(sizeof(OwnedController2f9030) == 0x30, "OwnedController2f9030 size");
