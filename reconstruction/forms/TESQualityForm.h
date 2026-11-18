// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESQualityForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// TESQualityForm::ClearDataComponent, TESQualityForm::InitializeDataComponent, TESQualityForm::~TESQualityForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class TESQualityForm : public BaseFormComponent
{
public:
    TESQualityForm();
    virtual void ClearDataComponent();  // compared: 0x1ef660
    virtual void InitializeDataComponent();  // compared: 0x1ef650
    virtual ~TESQualityForm() {}  // compared: 0x1ef6e0 (scalar deleting destructor)

    std::uint32_t value08;      // 08
    std::uint8_t  unknown0C[0x4];  // 0C
};
static_assert(sizeof(TESQualityForm) == 0x10, "TESQualityForm size");
