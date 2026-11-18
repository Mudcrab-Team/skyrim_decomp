// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSkinForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSSkinForm::ClearDataComponent, BGSSkinForm::InitializeDataComponent, BGSSkinForm::~BGSSkinForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class BGSSkinForm : public BaseFormComponent
{
public:
    BGSSkinForm();
    virtual void ClearDataComponent();  // compared: 0x1db8e0
    virtual void InitializeDataComponent();  // compared: 0x1db8d0
    virtual ~BGSSkinForm() {}  // compared: 0x1dbab0 (scalar deleting destructor)

    void* ptr08;  // 08
};
static_assert(sizeof(BGSSkinForm) == 0x10, "BGSSkinForm size");
