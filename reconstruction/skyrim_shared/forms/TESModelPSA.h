// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESModelPSA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent, TESModel: STANDIN EXE_RTTI
// TESModelPSA::~TESModelPSA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class TESModel : public BaseFormComponent
{
public:
    std::uint8_t unknown08[0x20];  // 08
};
static_assert(sizeof(TESModel) == 0x28, "TESModel size");

class TESModelPSA : public TESModel
{
public:
    TESModelPSA();
    virtual ~TESModelPSA();  // compared: 0x38af60 (scalar deleting destructor)
};
static_assert(sizeof(TESModelPSA) == 0x28, "TESModelPSA size");
