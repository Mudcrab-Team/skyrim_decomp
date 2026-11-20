// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSLocationRefType, BGSLocationRefType::~BGSLocationRefType, BGSLocationRefType::InitItemImpl, BGSKeyword, BGSKeyword::~BGSKeyword, BGSKeyword::Load, BGSKeyword::GetFormEditorID, BGSKeyword::SetFormEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's BGSKeyword.h omits the virtual destructor and slots 06 and 33 that this unit needs
// unknown20: GUESS(low)
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

class BGSLocationRefType : public BGSKeyword
{
public:
    virtual ~BGSLocationRefType();  // compared: 0x29e6b0  // slot 00
    void InitItemImpl() override;  // 13
    BGSLocationRefType();
};
static_assert(sizeof(BGSLocationRefType) == 0x28, "BGSLocationRefType size");
