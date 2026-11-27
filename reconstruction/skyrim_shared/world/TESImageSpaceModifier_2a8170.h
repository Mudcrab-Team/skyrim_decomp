// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// TESImageSpaceModifier, TESImageSpaceModifier::ClearData, TESForm, TESForm::ClearData, NiPointer, NiFloatInterpolator, NiFloatInterpolator::DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::m_uiRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declared on the stand-ins here
// VFunc01..VFunc03, pairs, ptr268..ptr2C8, unk08, unk20, _ptr: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiFloatInterpolator
{
public:
    virtual ~NiFloatInterpolator();
    virtual void DeleteThis();  // 01

    // volatile: reference count modified atomically across threads
    volatile long m_uiRefCount;  // 08
};

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* a_object)
    {
        if (_ptr != a_object) {
            if (a_object) {
                // The reference count is shared between threads.
                _InterlockedIncrement(&a_object->m_uiRefCount);
            }
            T* old = _ptr;
            _ptr = a_object;
            if (old) {
                // The reference count is shared between threads.
                const long count = _InterlockedDecrement(&old->m_uiRefCount);
                if (count == 0) {
                    old->DeleteThis();
                }
            }
        }
        return *this;
    }

    T* _ptr;
};

class TESForm
{
public:
    virtual ~TESForm();
    virtual void VFunc01(); virtual void VFunc02(); virtual void VFunc03();
    virtual void ClearData();  // callee at 0x1e36b0, not compared

    std::uint8_t unk08[0x18];  // 08..20
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

class TESImageSpaceModifier : public TESForm
{
public:
    void ClearData() override;  // compared: 0x2a8170

    std::uint8_t unk20[0xF8];                        // 20..118
    NiPointer<NiFloatInterpolator> pairs[21][2];     // 118..268 (42 pointers = 0x150)
    NiPointer<NiFloatInterpolator> ptr268;           // 268
    NiPointer<NiFloatInterpolator> ptr270;           // 270
    NiPointer<NiFloatInterpolator> ptr278;           // 278
    NiPointer<NiFloatInterpolator> ptr280;           // 280
    NiPointer<NiFloatInterpolator> ptr288;           // 288
    NiPointer<NiFloatInterpolator> ptr290;           // 290
    NiPointer<NiFloatInterpolator> ptr298;           // 298
    NiPointer<NiFloatInterpolator> ptr2A0;           // 2A0
    NiPointer<NiFloatInterpolator> ptr2A8;           // 2A8
    NiPointer<NiFloatInterpolator> ptr2B0;           // 2B0
    NiPointer<NiFloatInterpolator> ptr2B8;           // 2B8
    NiPointer<NiFloatInterpolator> ptr2C0;           // 2C0
    NiPointer<NiFloatInterpolator> ptr2C8;           // 2C8
};
static_assert(offsetof(TESImageSpaceModifier, pairs) == 0x118, "pairs offset");
static_assert(offsetof(TESImageSpaceModifier, ptr268) == 0x268, "ptr268 offset");
static_assert(offsetof(TESImageSpaceModifier, ptr2C8) == 0x2C8, "ptr2C8 offset");
