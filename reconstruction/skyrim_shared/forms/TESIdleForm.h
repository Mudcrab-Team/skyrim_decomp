// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The destructor is declared without a body in this unit: the deleting destructor calls the plain one
// at RVA 0x3b6a20, which is bound by hint. The members are not recovered. Adapted bodies: none declared.
// TESIdleForm, TESIdleForm::~TESIdleForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESIdleForm::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 13, RVA 0x3b7240
// TESIdleForm::unknown20, ::unknown28, ::unknown30, ::unknown38, ::unknown40, ::unknown48, ::unknown50: GUESS(low); the members from 0x20 to 0x57, named at their offsets
// TESIdleForm::GetFormEditorID, TESIdleForm::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 32, the editor ID text at 0x58
// BSString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSString::data, BSString::size, BSString::capacity, BSString::unknown0C, BSString::c_str, kEmptyString: GUESS(low)
#pragma once

#include <cstdint>

#include "TESForm.h"

// Empty text a BSString returns when it holds nothing; global in the image.
extern const char kEmptyString[];

// BSString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSString {
    const char* c_str() const
    {
        return data ? data : kEmptyString;
    }

    char*         data;      // 00
    std::uint16_t size;      // 08
    std::uint16_t capacity;  // 0A
    std::uint32_t unknown0C;  // 0C
};
static_assert(sizeof(BSString) == 0x10, "BSString size");

class TESIdleForm : public TESForm {
public:
    TESIdleForm();
    ~TESIdleForm() override;  // 00
    void InitItemImpl() override;  // 13
    const char* GetFormEditorID() const override;  // 32

    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    BSString formEditorID;    // 58
};
static_assert(sizeof(TESIdleForm) == 0x68, "layout");
