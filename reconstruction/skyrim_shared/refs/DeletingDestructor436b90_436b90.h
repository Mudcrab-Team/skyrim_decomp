// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiPointer::~NiPointer, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DecRef, DeletingDestructor436b90, ms_totalObjects, ptr, refObj, unk0C, unk18: GUESS(low) STANDIN; community list calls 0x436b90 ConeProjectile::InitNonNPCAnimation, which does not fit a 0x20-byte deleting destructor
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    NiRefObject();
    virtual ~NiRefObject()
    {
        // hot path: atomic total object count decrement on destruction
        _InterlockedDecrement(&ms_totalObjects);
    }
    virtual void DeleteThis();

    void DecRef()
    {
        // hot path: atomic reference release on smart pointer destruction
        if (_InterlockedExchangeAdd(&_refCount, -1) == 1)
        {
            DeleteThis();
        }
    }

    // volatile: global object counter updated atomically across threads
    static volatile long ms_totalObjects;

    // volatile: intrusive reference count updated atomically across threads
    volatile long _refCount;  // 08
    std::uint32_t unk0C;      // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

template <class T>
class NiPointer
{
public:
    NiPointer() : ptr(nullptr) {}

    ~NiPointer()
    {
        if (ptr)
        {
            ptr->DecRef();
        }
    }

    T* ptr;  // 00
};

class DeletingDestructor436b90 : public NiRefObject
{
public:
    DeletingDestructor436b90();

    NiPointer<NiRefObject> refObj;  // 10
    std::uint64_t          unk18;   // 18
};
static_assert(sizeof(DeletingDestructor436b90) == 0x20, "DeletingDestructor436b90 size");
