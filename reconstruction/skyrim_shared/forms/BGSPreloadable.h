// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSPreloadable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSPreloadable::ClearDataComponent, BGSPreloadable::CopyComponent, BGSPreloadable::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BaseFormComponent;

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class BGSPreloadable : public BaseFormComponent
{
public:
    virtual void ClearDataComponent();  // compared: 0x2601d0
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // compared: 0x2601e0
    virtual void InitializeDataComponent();  // compared: 0x2601f0
};
static_assert(sizeof(BGSPreloadable) == 0x8, "BGSPreloadable size");
