// Source exposure: mixed (pinned image listing; CrashLogger PDB names; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17d2b0::~RefPtr17d2b0 and RefTarget17d2b0::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget17d2b0: GUESS(low)
// RefPtr17d2b0: GUESS(low)
// BSExtraData17d2b0: GUESS(low)
// ExtraMultiBound17d2b0: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct RefTarget17d2b0
{
    virtual ~RefTarget17d2b0();
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

struct RefPtr17d2b0
{
    ~RefPtr17d2b0()
    {
        if (ptr != nullptr)
        {
            ptr->DecRef();
        }
    }

    RefTarget17d2b0* ptr;
};

struct BSExtraData17d2b0
{
    virtual ~BSExtraData17d2b0()
    {
    }

    BSExtraData17d2b0* next;
};

struct ExtraMultiBound17d2b0 : BSExtraData17d2b0
{
    ExtraMultiBound17d2b0();
    ~ExtraMultiBound17d2b0() override = default;

    RefPtr17d2b0 target;
};

static_assert(sizeof(ExtraMultiBound17d2b0) == 0x18, "ExtraMultiBound17d2b0 size");
