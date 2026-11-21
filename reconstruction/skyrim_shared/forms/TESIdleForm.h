// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from binary analysis; no external implementation code copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The destructor is declared without a body in this unit: the deleting destructor calls the plain one
// at RVA 0x3b6a20, which is bound by hint. The members are not recovered. Adapted bodies: none declared.
// TESIdleForm, TESIdleForm::~TESIdleForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESIdleForm::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 13, RVA 0x3b7240
// TESIdleForm::unk20: GUESS(low); stands for the members from 0x20 to 0x67
#pragma once

#include <cstdint>

#include "TESForm.h"

class TESIdleForm : public TESForm {
public:
    TESIdleForm();
    ~TESIdleForm() override;  // 00
    void InitItemImpl() override;  // 13
    // TESIdleForm::GetFormEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    const char* GetFormEditorID() const override;  // 32

    std::uint8_t unk20[0x38];  // 20
    // editorID: GUESS(low); the editor-id string pointer read by GetFormEditorID
    const char* editorID;  // 58
    std::uint8_t unk60[0x8];  // 60
};
static_assert(sizeof(TESIdleForm) == 0x68, "layout");
