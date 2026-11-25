// Source exposure: mixed (community headers; the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; NiRefObject reference-count helpers adapted as stated below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to what this function uses
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function uses
// _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:14074
// IncRefCount, DecRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Function7217e0, ProcessOwner, Held, unk08, unk1A8: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();

    void IncRefCount()
    {
        _InterlockedIncrement(&_refCount);  // the count is shared across threads
    }

    void DecRefCount()
    {
        // the count is shared across threads
        if (_InterlockedExchangeAdd(&_refCount, -1) == 1) {
            delete this;
        }
    }

    volatile long _refCount;
    std::uint32_t pad0C;
};

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* other)
    {
        if (other != _ptr) {
            T* old = _ptr;
            if (other) {
                other->IncRefCount();
            }
            _ptr = other;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class Held : public NiRefObject
{
};

class ProcessOwner
{
public:
    char unk000[0x1A8];
    NiPointer<Held> unk1A8;
};

class ActorProcess
{
public:
    bool Function7217e0(NiPointer<Held>& out);

    char unk000[0x8];
    ProcessOwner* unk08;
};
