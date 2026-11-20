// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSReferenceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSReferenceEffect::~BGSReferenceEffect, ClearData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSArtObject, TESEffectShader: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// artObject, effectShader, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BGSArtObject;
class TESEffectShader;

class BGSReferenceEffect : public TESForm
{
public:
    BGSReferenceEffect();
    ~BGSReferenceEffect() override;
    void ClearData() override;

private:
    BGSArtObject* artObject;
    TESEffectShader* effectShader;
    std::uint32_t flags;
};
static_assert(sizeof(BGSReferenceEffect) == 0x38, "observed allocation size");
