// Source exposure: mixed (pinned image listing; CrashLogger PDB names; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr17d980::~RefPtr17d980 and RefTarget17d980::DecRef, treated as adapted: shaped like NiPointer::~NiPointer and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RefTarget17d980: GUESS(low)
// RefPtr17d980: GUESS(low)
// BSExtraData17d980: GUESS(low)
// ExtraRoom17d980: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

struct RefTarget17d980
{
    virtual ~RefTarget17d980();
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

struct RefPtr17d980
{
    ~RefPtr17d980()
    {
        if (ptr != nullptr)
        {
            ptr->DecRef();
        }
    }

    RefTarget17d980* ptr;
};

struct BSExtraData17d980
{
    virtual ~BSExtraData17d980()
    {
    }

    BSExtraData17d980* next;
};

struct ExtraRoom17d980 : BSExtraData17d980
{
    ExtraRoom17d980();
    ~ExtraRoom17d980() override = default;

    RefPtr17d980 target;
};

static_assert(sizeof(ExtraRoom17d980) == 0x18, "ExtraRoom17d980 size");
