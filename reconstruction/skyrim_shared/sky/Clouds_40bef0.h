// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Clouds, Clouds::clouds, Clouds::unk110, Clouds::transTexture, SkyObject, SkyObject::root: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets, the element types of the last two arrays are reduced to their destructors
// BSGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a reference-counted object
// CloudTexture, TransTexture, Clouds::Function40cce0, Clouds::unk310: STANDIN GUESS(low); names made up for the array elements, the callee at 0x40cce0 and the members the function does not access
// Clouds::~Clouds: GUESS(low); the CrashLogger map calls 0x40bef0 a constructor, but the body releases the members as a destructor does
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();  // 01

    // hot path: the engine counts references atomically, as NiRefObject::IncRefCount does
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        // hot path: the engine releases references atomically, as NiRefObject::DecRefCount does
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0) {
            DeleteThis();
        }
    }

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (_ptr) {
            _ptr->DecRefCount();
        }
    }
    NiPointer& operator=(T* a_object)
    {
        if (_ptr != a_object) {
            if (a_object) {
                a_object->IncRefCount();
            }
            T* old = _ptr;
            _ptr = a_object;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class BSGeometry : public NiRefObject {};

// Element types of the other two arrays; their destructors are separate functions in the image.
class CloudTexture
{
public:
    ~CloudTexture();  // callee at 0x24da80, not compared here
    void* unk00;
};

class TransTexture
{
public:
    ~TransTexture();  // callee at 0x1b29d0, not compared here
    void* unk00;
};

class SkyObject
{
public:
    SkyObject();
    virtual ~SkyObject();  // callee at 0x41a180, not compared here

    void* root;  // 08
};

class Clouds : public SkyObject
{
public:
    Clouds();
    ~Clouds() override;  // compared: 0x40bef0
    void Function40cce0();  // callee at 0x40cce0, not compared here

    NiPointer<BSGeometry> clouds[32];  // 010
    CloudTexture unk110[32];           // 110
    TransTexture transTexture[32];     // 210
    std::uint8_t unk310[0x520 - 0x310];  // 310
};
static_assert(sizeof(Clouds) == 0x520, "Clouds size");
