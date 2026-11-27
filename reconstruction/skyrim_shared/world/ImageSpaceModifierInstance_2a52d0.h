// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstance, ImageSpaceModifierInstance::~ImageSpaceModifierInstance, ImageSpaceModifierInstance::unk10, ImageSpaceModifierInstance::strength, ImageSpaceModifierInstance::target, ImageSpaceModifierInstance::age, ImageSpaceModifierInstance::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout, the destructor body is read from the listing
// ImageSpaceModifierInstance::Apply, ImageSpaceModifierInstance::PrintInfo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared only so the vtable has the slots
// NiRefObject, NiObject, NiAVObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the destructor touches
// NiRefObject::DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; DeleteThis is virtual slot 01
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// Adapted bodies: none. The origin check reports NiAVObject::IncRefCount, NiPointer::~NiPointer as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:46360
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// g_objectCount: GUESS(low); the global object counter that the base destructor decrements
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

// volatile: the counter is changed atomically with interlocked operations
extern volatile long g_objectCount;

class NiRefObject
{
public:
    // hot path: the engine counts live objects atomically
    virtual ~NiRefObject() { _InterlockedDecrement(&g_objectCount); }
    virtual void DeleteThis();  // 01

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

class NiObject : public NiRefObject
{
public:
    ~NiObject() override {}
};

class NiAVObject : public NiObject
{
public:
    // hot path: the engine counts references atomically, as NiRefObject::IncRefCount does
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
    // hot path: the engine counts references atomically, as NiRefObject::DecRefCount does
    void DecRefCount()
    {
        // hot path: the engine releases references atomically
        const long count = _InterlockedDecrement(&m_uiRefCount);
        if (count == 0) {
            DeleteThis();
        }
    }
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

class ImageSpaceModifierInstance : public NiObject
{
public:
    ~ImageSpaceModifierInstance() override;  // compared: 0x2a52d0
    virtual void Apply() = 0;
    virtual void PrintInfo(char* a_dstBuf) = 0;

    std::uint8_t unk10;           // 10
    float strength;               // 14
    NiPointer<NiAVObject> target; // 18
    float age;                    // 20
    std::uint32_t flags;          // 24
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "layout");
