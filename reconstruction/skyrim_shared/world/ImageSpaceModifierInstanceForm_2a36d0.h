// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiAVObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:46360
// ImageSpaceModifierInstanceForm::SetTarget: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceModifierInstanceForm, ImageSpaceModifierInstance, TESImageSpaceModifier, NiObject, NiAVObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceModifierInstance::unk10, ImageSpaceModifierInstance::strength, ImageSpaceModifierInstance::target, ImageSpaceModifierInstance::age, ImageSpaceModifierInstance::flags, ImageSpaceModifierInstanceForm::imod, ImageSpaceModifierInstanceForm::unk30, ImageSpaceModifierInstanceForm::unk38, ImageSpaceModifierInstanceForm::unk3C, ImageSpaceModifierInstanceForm::unk40, ImageSpaceModifierInstanceForm::unk48, NiAVObject::DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::m_uiRefCount, NiRefObject::IncRefCount, NiRefObject::DecRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declared on the stand-ins here
// SetTarget parameters, g_defaultAge, unk00, unk0C, unk20, unk4C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiObject
{
public:
    virtual ~NiObject();
    virtual void DeleteThis();

    // volatile: reference count modified atomically across threads
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;         // 0C
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiAVObject : public NiObject
{
public:
    // The reference count is shared between threads.
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        // The reference count is shared between threads.
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
    NiPointer& operator=(T* a_object)
    {
        T* old = _ptr;
        if (old != a_object) {
            if (a_object) {
                a_object->IncRefCount();
            }
            _ptr = a_object;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    NiPointer& operator=(const NiPointer& a_other)
    {
        if (_ptr != a_other._ptr) {
            T* old = _ptr;
            T* incoming = a_other._ptr;
            if (incoming) {
                incoming->IncRefCount();
            }
            _ptr = incoming;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class TESImageSpaceModifier
{
public:
    std::uint8_t unk00[0x20];
    bool unk20;  // 20
};

class ImageSpaceModifierInstance : public NiObject
{
public:
    ~ImageSpaceModifierInstance() override;

    std::uint8_t unk10;            // 10
    float strength;                // 14
    NiPointer<NiAVObject> target;  // 18
    float age;                     // 20
    std::uint32_t flags;           // 24
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "ImageSpaceModifierInstance size");

class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
{
public:
    bool SetTarget(TESImageSpaceModifier* a_imod, float a_strength, float a_arg3, NiAVObject* a_target);  // compared: 0x2a36d0

    TESImageSpaceModifier* imod;    // 28
    TESImageSpaceModifier* unk30;   // 30
    float unk38;                  // 38
    std::uint32_t unk3C;          // 3C
    NiPointer<NiAVObject> unk40;  // 40
    float unk48;                  // 48
    std::uint32_t unk4C;          // 4C
};
static_assert(sizeof(ImageSpaceModifierInstanceForm) == 0x50, "ImageSpaceModifierInstanceForm size");

extern float g_defaultAge;
