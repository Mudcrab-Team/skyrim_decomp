// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESImageSpaceModifiableForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// TESImageSpaceModifiableForm::ClearDataComponent, TESImageSpaceModifiableForm::InitializeDataComponent, TESImageSpaceModifiableForm::~TESImageSpaceModifiableForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: GUESS(low)
// data08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESImageSpaceModifiableForm : public BaseFormComponent
{
public:
    TESImageSpaceModifiableForm();
    virtual void ClearDataComponent();  // compared: 0x1e8660
    virtual void InitializeDataComponent();  // compared: 0x1e8650
    virtual ~TESImageSpaceModifiableForm() {}  // compared: 0x1e8760 (scalar deleting destructor; target inlines this destructor)

    void* data08;  // 08
};
static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10, "TESImageSpaceModifiableForm size");
