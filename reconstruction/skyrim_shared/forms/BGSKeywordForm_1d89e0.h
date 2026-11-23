// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSKeywordForm, BGSKeywordForm::~BGSKeywordForm, BGSKeywordForm::InitializeDataComponent, BGSKeywordForm::ClearDataComponent, BGSKeywordForm::CopyComponent, BGSKeywordForm::HasKeyword, BGSKeywordForm::GetDefaultKeyword, BGSKeywordForm::keywords, BGSKeywordForm::numKeywords, BGSKeywordForm::pad14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstddef>
#include <cstdint>
#include "declarations/BaseFormComponent.h"

class BGSKeyword;

class BGSKeywordForm : public BaseFormComponent
{
public:
    ~BGSKeywordForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual bool HasKeyword(const BGSKeyword* a_keyword) const;  // 04; compared: 0x1d89e0
    virtual BGSKeyword* GetDefaultKeyword() const;  // 05

    BGSKeyword** keywords;  // 08
    std::uint32_t numKeywords;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(offsetof(BGSKeywordForm, keywords) == 0x08, "keywords offset");
static_assert(offsetof(BGSKeywordForm, numKeywords) == 0x10, "numKeywords offset");
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");
