// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSAttackDataForm: GUESS(low); the class is the placeholder owner
// SetAttackData: GUESS(low); the name is made up
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

class BGSAttackDataForm
{
public:
    void SetAttackData(AttackData* a_data);  // compared: 0x1d1d50

    std::uint8_t pad00[0x8];
    AttackData* attackData;
};
