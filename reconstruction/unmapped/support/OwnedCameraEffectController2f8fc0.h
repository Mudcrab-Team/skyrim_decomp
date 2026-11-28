// Source exposure: mixed (pinned image listing; community source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: SmartPtr2f8fc0::~SmartPtr2f8fc0 and RefObj2f8fc0::Release, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// OwnedCameraEffectController2f8fc0: CRASHLOGGER_PDB(59818@2026.10.24)
// RefObj2f8fc0, SmartPtr2f8fc0, Base2f8fc0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class RefObj2f8fc0
{
public:
    virtual ~RefObj2f8fc0();
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

class SmartPtr2f8fc0
{
public:
    ~SmartPtr2f8fc0()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }

    RefObj2f8fc0* m_ptr;  // 0x00
};

class Base2f8fc0
{
public:
    virtual ~Base2f8fc0();

    std::uint64_t unk08[4];  // 0x08
};
static_assert(sizeof(Base2f8fc0) == 0x28, "Base2f8fc0 size");

class OwnedCameraEffectController2f8fc0 : public Base2f8fc0
{
public:
    OwnedCameraEffectController2f8fc0();
    ~OwnedCameraEffectController2f8fc0() override = default;

    SmartPtr2f8fc0 m_owner;  // 0x28
    std::uint64_t unk30;     // 0x30
};
static_assert(sizeof(OwnedCameraEffectController2f8fc0) == 0x38, "OwnedCameraEffectController2f8fc0 size");
