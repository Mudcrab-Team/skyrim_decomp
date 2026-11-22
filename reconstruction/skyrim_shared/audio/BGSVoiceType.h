// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSVoiceType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSVoiceType::SetFormEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

// FormEditorIDSet: GUESS(low); the callee at RVA 0x10d710, bound by the unit's bind-hints.json
void FormEditorIDSet(void* a_dest, const char* a_str, bool a_flag);

class BGSVoiceType : public TESForm
{
public:
    virtual bool SetFormEditorID(const char* a_str);  // compared: 0x3aee30

    // unknown20, unk28: GUESS(low)
    std::uint8_t unknown20[0x8];  // 20
    std::uint8_t unk28[0x8];      // 28
};
