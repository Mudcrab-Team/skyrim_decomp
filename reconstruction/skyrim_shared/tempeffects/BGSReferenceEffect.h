// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSReferenceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSReferenceEffect::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BGSReferenceEffect : public TESForm
{
public:
    virtual void InitializeData();  // compared: 0x29ec10

    // unknown20: GUESS(low)
    std::uint64_t unknown20;  // 20
    // unknown28: GUESS(low)
    std::uint64_t unknown28;  // 28
    // unknown30: GUESS(low)
    std::uint32_t unknown30;  // 30
};
