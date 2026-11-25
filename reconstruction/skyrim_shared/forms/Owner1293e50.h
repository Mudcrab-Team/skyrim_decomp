// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x26b3e0 (skyrim_shared/forms/TESEffectShader): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The members of EffectShaderData and the layout after it are not claimed. Adapted bodies: none declared.
// ::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectShaderData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); size 0x1A0 from NG
// Owner1293e50: GUESS(low) STANDIN
// GetTotalDuration, GetFadeInAndFullDuration: GUESS(low) STANDIN
#pragma once
#include "TESEffectShader.h"

class Owner1293e50 : public TESForm {
public:
    void InitializeData() override;  // 04
    void InitItemImpl() override;    // 13
    float GetTotalDuration() const;
    float GetFadeInAndFullDuration() const;

    EffectShaderData data;           // 20
    std::uint8_t     unk1C0[0x60];   // 1C0
};
static_assert(sizeof(Owner1293e50) == 0x220, "layout");
