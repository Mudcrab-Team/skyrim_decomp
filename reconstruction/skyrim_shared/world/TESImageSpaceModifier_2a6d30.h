// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImageSpaceModifier, TESForm, TESImageSpaceModifier::ClearData, BSString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the members this destructor releases
// NiInterpolator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a reference-counted object
// TESImageSpaceModifier::interpolator268, TESImageSpaceModifier::interpolator270, TESImageSpaceModifier::interpolator278, TESImageSpaceModifier::interpolator280, TESImageSpaceModifier::interpolator288, TESImageSpaceModifier::interpolator290, TESImageSpaceModifier::interpolator298, TESImageSpaceModifier::interpolator2A0, TESImageSpaceModifier::interpolator2A8, TESImageSpaceModifier::interpolator2B0, TESImageSpaceModifier::interpolator2B8, TESImageSpaceModifier::interpolator2C0, TESImageSpaceModifier::interpolator2C8, TESImageSpaceModifier::keyInterpolators: GUESS(low); names made up from the offsets; ClearData is the callee at 0x2a8170
// TESImageSpaceModifier::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the string member this destructor releases
// NiRefObject, NiRefObject::DeleteThis, NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); the name only
// Adapted bodies: none. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount, TESImageSpaceModifier::~TESImageSpaceModifier as similar to bodies cited below (sibling files, CC0-1.0); ours are short forms written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesimagespacemodifier.cpp:886
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

class NiInterpolator : public NiRefObject {};

class BSString
{
public:
    ~BSString();  // callee at 0x10d6a0, not compared here

    char* data;
    std::uint64_t size;
};

class TESForm
{
public:
    virtual ~TESForm();  // callee at 0x1e3350, not compared here

    std::uint8_t unk08[0x18];
};

class TESImageSpaceModifier : public TESForm
{
public:
    TESImageSpaceModifier();
    ~TESImageSpaceModifier() override;  // compared: 0x2a6d30
    void ClearData();                   // callee at 0x2a8170, not compared here

    std::uint8_t unk20[0xF8];                       // 20
    NiPointer<NiInterpolator> keyInterpolators[42];  // 118
    NiPointer<NiInterpolator> interpolator268;  // 268
    NiPointer<NiInterpolator> interpolator270;  // 270
    NiPointer<NiInterpolator> interpolator278;  // 278
    NiPointer<NiInterpolator> interpolator280;  // 280
    NiPointer<NiInterpolator> interpolator288;  // 288
    NiPointer<NiInterpolator> interpolator290;  // 290
    NiPointer<NiInterpolator> interpolator298;  // 298
    NiPointer<NiInterpolator> interpolator2A0;  // 2A0
    NiPointer<NiInterpolator> interpolator2A8;  // 2A8
    NiPointer<NiInterpolator> interpolator2B0;  // 2B0
    NiPointer<NiInterpolator> interpolator2B8;  // 2B8
    NiPointer<NiInterpolator> interpolator2C0;  // 2C0
    NiPointer<NiInterpolator> interpolator2C8;  // 2C8
    BSString formEditorID;  // 2D0
};
static_assert(sizeof(TESImageSpaceModifier) == 0x2E0, "TESImageSpaceModifier size");
