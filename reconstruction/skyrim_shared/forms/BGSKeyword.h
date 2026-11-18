// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its
// BGSKeyword, BGSKeyword::GetFormEditorID, BGSKeyword::formEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString, BSFixedString::_data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the string pointer at offset 0 is claimed, public here
#pragma once

#include <cstdint>

#include "TESForm.h"

class BSFixedString {
public:
    const char* _data;  // 00
};

class BGSKeyword : public TESForm {
public:
    const char* GetFormEditorID() const override;  // 32

    BSFixedString formEditorID;  // 20
};
