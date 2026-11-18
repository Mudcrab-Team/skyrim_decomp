// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSBipedObjectForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSBipedObjectForm::ClearDataComponent, BGSBipedObjectForm::InitializeDataComponent, BGSBipedObjectForm::~BGSBipedObjectForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: GUESS(low)
// unk08, unknown0C: GUESS(low); unk08 is the dword the initialiser stores zero into
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class BGSBipedObjectForm : public BaseFormComponent
{
public:
    BGSBipedObjectForm();
    virtual void ClearDataComponent();  // compared: 0x1d20f0
    virtual void InitializeDataComponent();  // compared: 0x1d20e0
    virtual ~BGSBipedObjectForm();  // compared: 0x1d21f0 (scalar deleting destructor)

    std::uint32_t unk08;  // 08
    std::uint8_t unknown0C[0x4];  // 0C
};
static_assert(sizeof(BGSBipedObjectForm) == 0x10, "BGSBipedObjectForm size");
