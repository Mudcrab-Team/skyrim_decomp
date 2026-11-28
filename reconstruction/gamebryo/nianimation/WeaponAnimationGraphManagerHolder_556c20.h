// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// WeaponAnimationGraphManagerHolder, WeaponAnimationGraphManagerHolder::SetAnimationGraphManagerImpl, animationGraphManager, BSAnimationGraphManager: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTSmartPointer, refCount: GUESS(low) STANDIN
#pragma once

#include <intrin.h>
#include <cstddef>
#include <cstdint>

class BSAnimationGraphManager
{
public:
    virtual ~BSAnimationGraphManager();

    long refCount;
};

template <class T>
struct BSTSmartPointer
{
    BSTSmartPointer& operator=(const BSTSmartPointer& a_rhs)
    {
        T* incoming = a_rhs.ptr;
        T* previous = ptr;
        if (incoming != previous)
        {
            if (incoming != nullptr)
            {
                // engine atomic reference count increment
                _InterlockedIncrement(&incoming->refCount);
            }
            ptr = incoming;
            if (previous != nullptr)
            {
                // engine atomic reference count decrement
                if (_InterlockedExchangeAdd(&previous->refCount, -1) - 1 == 0)
                {
                    delete previous;
                }
            }
        }
        return *this;
    }

    T* ptr;
};

class WeaponAnimationGraphManagerHolder
{
public:
    bool SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& a_in);

    std::uint8_t unk00[0x10];
    BSTSmartPointer<BSAnimationGraphManager> animationGraphManager;
};

static_assert(offsetof(BSAnimationGraphManager, refCount) == 0x08, "refCount offset");
static_assert(offsetof(WeaponAnimationGraphManagerHolder, animationGraphManager) == 0x10, "animationGraphManager offset");
