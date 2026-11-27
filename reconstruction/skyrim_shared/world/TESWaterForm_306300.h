// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterForm, TESForm, BaseFormComponent, TESFullName, TESFullName::fullName, TESAttackDamageForm, BSFixedString, TESTexture, TESWaterForm::noiseTextures, TESWaterForm::noiseTextureData, TESWaterForm::placeableAutoWater, TESWaterForm::placeableLODWater: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout, the two four-element arrays appear as separate members
// NiTexture, TESObjectACTI: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the function touches
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

class NiTexture : public NiRefObject {};

class TESObjectACTI
{
public:
    virtual ~TESObjectACTI();
};

class BSFixedString
{
public:
    ~BSFixedString();  // callee at 0xeb1100, not compared here

    const char* data;
};

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}
};

class TESForm : public BaseFormComponent
{
public:
    ~TESForm() override;  // callee at 0x1e3350, not compared here

    std::uint8_t unk08[0x18];
};

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override {}

    BSFixedString fullName;  // 08
};

class TESAttackDamageForm : public BaseFormComponent
{
public:
    ~TESAttackDamageForm() override;  // callee at 0x1df0a0, not compared here

    std::uint64_t unk08;
};

class TESTexture
{
public:
    ~TESTexture();  // callee at 0x1f2a20, not compared here

    std::uint8_t unk00[0x10];
};

class TESWaterForm : public TESForm, public TESFullName, public TESAttackDamageForm
{
public:
    ~TESWaterForm() override;  // compared: 0x306300

    std::uint8_t unk40[0x38];                  // 40
    TESTexture noiseTexture0;                  // 78
    TESTexture noiseTexture1;                  // 88
    TESTexture noiseTexture2;                  // 98
    TESTexture noiseTexture3;                  // A8
    std::uint8_t unkB8[0x200 - 0xb8];          // B8
    NiPointer<NiTexture> noiseTextureData0;    // 200
    NiPointer<NiTexture> noiseTextureData1;    // 208
    NiPointer<NiTexture> noiseTextureData2;    // 210
    NiPointer<NiTexture> noiseTextureData3;    // 218
    TESObjectACTI* placeableAutoWater;         // 220
    TESObjectACTI* placeableLODWater;          // 228
};
static_assert(offsetof(TESWaterForm, placeableLODWater) == 0x228, "layout");
