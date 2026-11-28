// Source exposure: mixed (pinned image listing; CrashLogger PDB names; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17c430::~RefPtr17c430 and RefTarget17c430::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget17c430: GUESS(low)
// RefPtr17c430: GUESS(low)
// BSExtraData17c430: GUESS(low)
// ExtraCell3D17c430: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct RefTarget17c430
{
    virtual ~RefTarget17c430();
    virtual void DeleteThis();

    void DecRef()
    {
        // Atomic intrusive reference count decrement.
        if (_InterlockedDecrement(&refCount) == 0)
        {
            DeleteThis();
        }
    }

    long refCount;
};

struct RefPtr17c430
{
    ~RefPtr17c430()
    {
        if (ptr != nullptr)
        {
            ptr->DecRef();
        }
    }

    RefTarget17c430* ptr;
};

struct BSExtraData17c430
{
    virtual ~BSExtraData17c430()
    {
    }

    BSExtraData17c430* next;
};

struct ExtraCell3D17c430 : BSExtraData17c430
{
    ExtraCell3D17c430();
    ~ExtraCell3D17c430() override = default;

    RefPtr17c430 target;
};

static_assert(sizeof(ExtraCell3D17c430) == 0x18, "ExtraCell3D17c430 size");
