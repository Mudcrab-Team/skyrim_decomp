// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1d85e0 (skyrim_shared/forms/BGSKeywordForm): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner4a0cf0: GUESS(low) STANDIN
// BaseFormComponent, keywords, numKeywords: GUESS(low) STANDIN
#pragma once
#include "BGSKeywordForm.h"

class Owner4a0cf0 : public BaseFormComponent
{
public:
    Owner4a0cf0();
    virtual BGSKeyword* GetDefaultKeyword() const;
    virtual void InitializeDataComponent();

    BGSKeyword**  keywords;     // 08
    std::uint32_t numKeywords;  // 10
    std::uint32_t pad14;        // 14
};
static_assert(sizeof(Owner4a0cf0) == 0x18, "Owner4a0cf0 size");
