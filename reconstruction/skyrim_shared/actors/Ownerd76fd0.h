// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction written for this project from the pinned image listing; no body copied or adapted. Stamped as a twin of matched 0x3b2fb0 (skyrim_shared/actors/TESEyes): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm, TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFullName: EXE_RTTI; the layer order and the three vftable slots come from the image RTTI and the listing stores
// Ownerd76fd0: GUESS(low) STANDIN
// TESTexture, Ownerd76fd0, Ownerd76fd0::~Ownerd76fd0, Ownerd76fd0::InitializeData, Ownerd76fd0::flags, Ownerd76fd0::unknown41, Ownerd76fd0::unknown42, Ownerd76fd0::unknown44: GUESS(low) STANDIN
#pragma once
#include "TESEyes.h"

class Ownerd76fd0 : public TESForm, public TESFullName, public TESTexture
{
public:
    ~Ownerd76fd0() override;  // 00

    void InitializeData() override;  // 04

    unsigned char padTwin40[40];
    std::uint8_t flags;  // 40
    std::uint8_t unknown41;  // 41
    std::uint16_t unknown42;  // 42
    std::uint32_t unknown44;  // 44
};
static_assert(sizeof(Ownerd76fd0) == 0x70, "layout");
