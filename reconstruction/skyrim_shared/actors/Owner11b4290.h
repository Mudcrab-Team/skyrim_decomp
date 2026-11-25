// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction written for this project from the pinned image listing; no body copied or adapted. Stamped as a twin of matched 0x3b2fb0 (skyrim_shared/actors/TESEyes): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName: EXE_RTTI; the layer order and the three vftable slots come from the image RTTI and the listing stores
// Owner11b4290: GUESS(low) STANDIN
// TESTexture, Owner11b4290, Owner11b4290::~Owner11b4290, Owner11b4290::InitializeData, Owner11b4290::flags, Owner11b4290::unknown41, Owner11b4290::unknown42, Owner11b4290::unknown44: GUESS(low) STANDIN
#pragma once
#include "TESEyes.h"

class Owner11b4290 : public TESForm, public TESFullName, public TESTexture
{
public:
    ~Owner11b4290() override;  // 00

    void InitializeData() override;  // 04

    unsigned char padTwin40[1];
    std::uint8_t flags;  // 40
    std::uint8_t unknown41;  // 41
    std::uint16_t unknown42;  // 42
    std::uint32_t unknown44;  // 44
};
static_assert(sizeof(Owner11b4290) == 0x50, "layout");
