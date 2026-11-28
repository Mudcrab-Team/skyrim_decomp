// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: reconstruction using cited declarations and stand-in layouts; see Adapted bodies.
// Adapted bodies: NiPointer::~NiPointer, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBoolInterpolator, NiKeyBasedInterpolator, NiBoolData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointer, NiRefObject, DeleteThis, DecRef, refCount, ptr, unk08, unk18, data, unk28: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();  // 08

    void DecRef()
    {
        // hot path: atomic intrusive reference count decrement
        if (_InterlockedExchangeAdd(&refCount, -1) == 1)
        {
            DeleteThis();
        }
    }

    // volatile: intrusive reference count is modified atomically
    volatile long refCount;  // 08
};

class NiBoolData : public NiRefObject
{
};

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (ptr)
        {
            ptr->DecRef();
        }
    }

    T* ptr;  // 00
};

class NiKeyBasedInterpolator
{
public:
    virtual ~NiKeyBasedInterpolator();

    std::uint64_t unk08[2];  // 08
};
static_assert(sizeof(NiKeyBasedInterpolator) == 0x18, "NiKeyBasedInterpolator size");

class NiBoolInterpolator : public NiKeyBasedInterpolator
{
public:
    NiBoolInterpolator();

    std::uint64_t         unk18;  // 18
    NiPointer<NiBoolData> data;   // 20
    std::uint64_t         unk28;  // 28
};
static_assert(sizeof(NiBoolInterpolator) == 0x30, "NiBoolInterpolator size");
