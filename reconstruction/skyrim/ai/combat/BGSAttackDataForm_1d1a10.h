// Origin check: NiPointer::~NiPointer is independently written; these incidental similarity hits are not reused.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/bstreadtransfinterpolator.cpp:375
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:24410
// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackDataForm, BaseFormComponent, BGSAttackDataMap, NiPointer, attackDataMap, _ptr, _refCount, DeleteThis, InitializeDataComponent, ClearDataComponent, CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent, BGSAttackDataMap, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPointer release body: independently written from assigned local analysis.
#pragma once

#include <cstddef>
#include <intrin.h>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() {}
    virtual void InitializeDataComponent() = 0;
    virtual void ClearDataComponent() = 0;
    virtual void CopyComponent(BaseFormComponent*) {}
};

class BGSAttackDataMap
{
public:
    virtual ~BGSAttackDataMap();
    virtual void DeleteThis();
    // volatile: shared reference count is accessed with an atomic intrinsic.
    volatile long _refCount;
};

template<class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        T* ptr = _ptr;
        // Shared ownership requires an atomic last-reference test.
        if (ptr && _InterlockedDecrement(&ptr->_refCount) == 0)
            ptr->DeleteThis();
    }
    T* _ptr;
};

class BGSAttackDataForm : public BaseFormComponent
{
public:
    ~BGSAttackDataForm() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(BaseFormComponent*) override;
    NiPointer<BGSAttackDataMap> attackDataMap;
};
static_assert(sizeof(BaseFormComponent) == 8, "component prefix size");
static_assert(sizeof(BGSAttackDataForm) == 16, "attack map follows component prefix");
static_assert(offsetof(BGSAttackDataMap, _refCount) == 8, "shared reference count offset");
static_assert(offsetof(BGSAttackDataForm, attackDataMap) == 8, "attack map member offset");
