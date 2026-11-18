// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// BGSRelationship: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSRelationship::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../forms/TESForm.h"

class BGSRelationship : public TESForm
{
public:
    virtual void InitializeData();  // compared: 0x3a46b0

    // unk20, unk28, unk30, unk38: GUESS(low)
    void*         unk20;  // 20
    void*         unk28;  // 28
    void*         unk30;  // 30
    std::uint32_t unk38;  // 38
};
