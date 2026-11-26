// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceForm: CRASHLOGGER_PDB(59818@2026.10.24); name only
// ImageSpaceModifierInstance: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); size and an out-of-line destructor, the callee at 0x2a52d0
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a reference-counted object
// g_currentFormInstance, g_secondFormInstance: GUESS(low); the counted pointer the destructor releases and the two globals it clears
// ImageSpaceModifierInstanceForm::unk40: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a counted pointer at 40 in this destructor
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

class NiAVObject : public NiRefObject {};

class ImageSpaceModifierInstance
{
public:
    ImageSpaceModifierInstance();
    virtual ~ImageSpaceModifierInstance();  // callee at 0x2a52d0, not compared here

    std::uint8_t unk08[0x20];
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "layout");

class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
{
public:
    ImageSpaceModifierInstanceForm();  // the constructor makes the compiler emit the vftable and the deleting destructor at 0x2a55a0
    ~ImageSpaceModifierInstanceForm() override;

    std::uint8_t unk28[0x18];       // 28
    NiPointer<NiAVObject> unk40;    // 40
    std::uint8_t unk48[8];          // 48
};
static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50, "layout");

extern ImageSpaceModifierInstanceForm* g_currentFormInstance;
extern ImageSpaceModifierInstanceForm* g_secondFormInstance;
