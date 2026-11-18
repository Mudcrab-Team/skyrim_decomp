// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSStoryManagerTreeForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSStoryManagerTreeForm::~BGSStoryManagerTreeForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../forms/TESForm.h"

class BGSStoryManagerTreeForm;

class BGSStoryManagerTreeForm : public TESForm
{
public:
    BGSStoryManagerTreeForm();
    virtual ~BGSStoryManagerTreeForm();  // compared: 0x1c72c0 (scalar deleting destructor)
    // BGSStoryManagerTreeForm::GetChild, BGSStoryManagerTreeForm::QChildCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x1c7ce0, 0x1c8510
    virtual BGSStoryManagerTreeForm* GetChild(std::uint32_t a_idx) const;  // compared: 0x1c7ce0
    virtual std::uint32_t QChildCount() const;  // compared: 0x1c8510
    // unknown20: GUESS(low)
    std::uint8_t unknown20[0x8];
};
