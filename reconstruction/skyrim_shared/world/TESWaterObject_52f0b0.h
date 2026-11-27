// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterObject, TESWaterObject::plane, TESWaterObject::shape, TESWaterObject::waterRippleObject, TESWaterObject::waterType, TESWaterObject::unk38, TESWaterObject::reflections, TESWaterObject::displacement, TESWaterObject::normals, TESWaterObject::multiBounds, TESWaterObject::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's offsets
// NiPlane, BSTArray, BSTArrayBase, BSTriShape, NiAVObject, TESWaterForm, TESWaterReflections, TESWaterDisplacement, TESWaterNormals: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// BSTArrayAllocator: STANDIN GUESS(low); the allocator base of the array
// NiPlane::unk00: GUESS(low); the four floats are not split into a normal and a constant here
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the functions touch
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// g_niObjectCount: GUESS(low); the global object counter
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

// volatile: the counter is changed atomically with interlocked operations
extern volatile long g_niObjectCount;

class NiRefObject
{
public:
    // hot path: the engine counts live objects atomically
    NiRefObject() : m_uiRefCount(0) { _InterlockedIncrement(&g_niObjectCount); }
    // hot path: the engine counts live objects atomically
    virtual ~NiRefObject() { _InterlockedDecrement(&g_niObjectCount); }
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
    NiPointer() : _ptr(nullptr) {}
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

// The constructor of the plane is the callee at 0xef7430.
class NiPlane
{
public:
    NiPlane();

    float unk00[4];
};

class BSTArrayAllocator
{
public:
    BSTArrayAllocator();  // callee at 0xce0cb0, not compared here

    void* data;
    std::uint64_t capacity;
};

class BSTArrayBase
{
public:
    BSTArrayBase();  // callee at 0xce0970, not compared here

    std::uint64_t size;
};

class BSTArray : public BSTArrayAllocator, public BSTArrayBase
{
public:
    ~BSTArray();  // callee at 0x5225e0, not compared here
};
static_assert(sizeof(BSTArray) == 0x18, "array size");

class BSTriShape : public NiRefObject {};
class NiAVObject : public NiRefObject {};
class TESWaterReflections : public NiRefObject {};
class TESWaterDisplacement : public NiRefObject {};
class TESWaterNormals : public NiRefObject {};
class TESWaterForm;

class TESWaterObject : public NiRefObject
{
public:
    TESWaterObject();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x52f0b0
    ~TESWaterObject() override;

    NiPlane plane;                                   // 10
    NiPointer<BSTriShape> shape;                     // 20
    NiPointer<NiAVObject> waterRippleObject;         // 28
    TESWaterForm* waterType;                         // 30
    std::uint64_t unk38;                             // 38
    NiPointer<TESWaterReflections> reflections;      // 40
    NiPointer<TESWaterDisplacement> displacement;    // 48
    NiPointer<TESWaterNormals> normals;              // 50
    BSTArray multiBounds;                            // 58
    std::uint8_t flags;                              // 70
};
static_assert(sizeof(TESWaterObject) == 0x78, "TESWaterObject size");
