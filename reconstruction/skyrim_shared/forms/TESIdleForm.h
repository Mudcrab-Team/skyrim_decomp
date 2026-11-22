// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Existing unit plus original reconstruction of GetFormEditorID. Adapted bodies: none declared.
// TESIdleForm, TESIdleForm::~TESIdleForm, TESIdleForm::InitItemImpl, TESIdleForm::GetFormEditorID, TESIdleForm::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk20, unk60: GUESS(low)
#pragma once

#include <cstdint>

#include "TESForm.h"

class TESIdleForm : public TESForm {
public:
    TESIdleForm();
    ~TESIdleForm() override;  // 00
    void InitItemImpl() override;  // 13
    const char* GetFormEditorID() const override;  // 32

    std::uint8_t unk20[0x38];  // 20
    const char* formEditorID;  // 58
    std::uint8_t unk60[0x8];  // 60
};
static_assert(sizeof(TESIdleForm) == 0x68, "layout");
