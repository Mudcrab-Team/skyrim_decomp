// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESModelTri: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent, TESModel: STANDIN EXE_RTTI
// TESModelTri::~TESModelTri: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

class TESModelTri : public TESModel
{
public:
    TESModelTri();
    virtual ~TESModelTri();  // compared: 0x390fa0 (scalar deleting destructor)
};
static_assert(sizeof(TESModelTri) == 0x28, "TESModelTri size");
