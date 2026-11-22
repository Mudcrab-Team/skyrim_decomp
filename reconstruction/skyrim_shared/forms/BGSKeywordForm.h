// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSKeywordForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BaseFormComponent: STANDIN EXE_RTTI
// BGSKeywordForm::GetDefaultKeyword, BGSKeywordForm::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent::~BaseFormComponent, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSKeyword;

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent() = default;
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class BGSKeywordForm : public BaseFormComponent
{
public:
    BGSKeywordForm();
    virtual BGSKeyword* GetDefaultKeyword() const;  // compared: 0x14c8b0
    virtual void InitializeDataComponent();  // compared: 0x1d8690

    // keywords, numKeywords: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    BGSKeyword**  keywords;     // 08
    std::uint32_t numKeywords;  // 10
    std::uint32_t pad14;        // 14
};
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");
