// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESValueForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// TESValueForm::ClearDataComponent, TESValueForm::InitializeDataComponent, TESValueForm::~TESValueForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class TESValueForm : public BaseFormComponent
{
public:
    TESValueForm();
    virtual void ClearDataComponent();  // compared: 0x1f34d0
    virtual void InitializeDataComponent();  // compared: 0x1f34c0
    virtual ~TESValueForm();  // compared: 0x1f36d0 (scalar deleting destructor)

    std::uint32_t unk08;  // 08
    std::uint8_t unknown0C[0x4];  // 0C
};
static_assert(sizeof(TESValueForm) == 0x10, "TESValueForm size");
