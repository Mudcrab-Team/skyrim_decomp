// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSAction, BGSAction::~BGSAction, BGSKeyword, BGSKeyword::~BGSKeyword, BGSKeyword::Load, BGSKeyword::GetFormEditorID, BGSKeyword::SetFormEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's BGSKeyword.h omits the virtual destructor and slots 06 and 33 that this unit needs
// unknown20, unknown28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class BGSKeyword : public TESForm
{
public:
    ~BGSKeyword() override;  // 00
    bool Load(TESFile* a_mod) override;  // 06
    const char* GetFormEditorID() const override;  // 32
    bool SetFormEditorID(const char* a_str) override;  // 33

    std::uint64_t unknown20;  // 20
};
static_assert(sizeof(BGSKeyword) == 0x28, "BGSKeyword size");

class BGSAction : public BGSKeyword
{
public:
    virtual ~BGSAction();  // compared: 0x389080  // slot 00
    BGSAction();

    std::uint64_t unknown28;  // 28
};
static_assert(sizeof(BGSAction) == 0x30, "BGSAction size");
