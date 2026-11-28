// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: BSTSmartPointer::~BSTSmartPointer, treated as adapted: it has the shape of NiPointer::~NiPointer, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: CC0-1.0
// WeaponAnimationGraphManagerHolder, IAnimationGraphManagerHolder, BSAnimationGraphManager, animationGraphManager: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTSmartPointer, refCount: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class BSAnimationGraphManager
{
public:
    virtual ~BSAnimationGraphManager();

    long refCount;
};

template <class T>
class BSTSmartPointer
{
public:
    ~BSTSmartPointer()
    {
        T* target = ptr;
        if (target != nullptr)
        {
            // engine atomic reference count decrement
            if (_InterlockedExchangeAdd(&target->refCount, -1) == 1)
            {
                delete target;
            }
        }
    }

    T* ptr;
};

class IAnimationGraphManagerHolder
{
public:
    virtual ~IAnimationGraphManagerHolder();
};

class WeaponAnimationGraphManagerHolder : public IAnimationGraphManagerHolder
{
public:
    WeaponAnimationGraphManagerHolder();
    ~WeaponAnimationGraphManagerHolder() override;

    std::uint64_t unk08;
    BSTSmartPointer<BSAnimationGraphManager> animationGraphManager;
};

static_assert(offsetof(WeaponAnimationGraphManagerHolder, animationGraphManager) == 0x10, "animationGraphManager offset");
static_assert(sizeof(WeaponAnimationGraphManagerHolder) == 0x18, "WeaponAnimationGraphManagerHolder size");
