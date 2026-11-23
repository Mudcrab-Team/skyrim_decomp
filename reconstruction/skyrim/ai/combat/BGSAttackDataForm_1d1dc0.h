// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// AttackDataPtr: GUESS(low); a smart pointer stand-in that owns the function; the placeholder class BGSAttackDataForm is unused
// Assign: GUESS(low); the name is made up
// AttackData, DeleteThis, IncRef, DecRef, refCount, attackData, unk00, unk01, pad00: GUESS(low); minimal stand-ins, layout from the listing
#pragma once

#include <cstdint>
#include <intrin.h>

class AttackData
{
public:
    virtual void unk00();
    virtual void DeleteThis();

    void IncRef()
    {
        // thread-safe reference count shared across the AI threads
        _InterlockedIncrement(&refCount);
    }

    void DecRef()
    {
        // thread-safe reference count shared across the AI threads
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }

    volatile long refCount;
};

class AttackDataPtr
{
public:
    AttackDataPtr& Assign(const AttackDataPtr& a_other);  // compared: 0x1d1dc0

    AttackData* ptr;
};
