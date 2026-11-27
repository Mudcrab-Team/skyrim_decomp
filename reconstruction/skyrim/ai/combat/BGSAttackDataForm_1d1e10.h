// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: reconstructed from the pinned image listing; names and prototypes as labelled below; see Adapted bodies
// Adapted bodies: NiPointer::~NiPointer, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:36
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackDataForm: EXE_RTTI
// BGSAttackDataForm::~BGSAttackDataForm: CRASHLOGGER_PDB(59818@2026.10.24)
// BaseFormComponent, NiRefObject, NiRefObject::DeleteThis, BGSAttackDataMap, BGSAttackDataForm::attackDataMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::refCount, NiPointer, NiPointer::ptr: GUESS(low); intrusive ref-count layout observed in listing
#pragma once

#include <cstdint>
#include <intrin.h>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}  // 00
};

class NiRefObject
{
public:
    virtual ~NiRefObject();     // 00
    virtual void DeleteThis();  // 01

    void DecRefCount()
    {
        // intrusive ref-count: atomic release of shared NiRefObject
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

class BGSAttackDataMap : public NiRefObject
{
};

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (ptr) {
            ptr->DecRefCount();
        }
    }

    T* ptr;  // 00
};

class BGSAttackDataForm : public BaseFormComponent
{
public:
    BGSAttackDataForm();
    ~BGSAttackDataForm() override;

    NiPointer<BGSAttackDataMap> attackDataMap;  // 08
};
static_assert(sizeof(BGSAttackDataForm) == 0x10, "BGSAttackDataForm size");
