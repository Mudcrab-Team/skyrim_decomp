// Code origin: original; the listing and community declarations only
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// The members of EffectShaderData and the layout after it are not claimed. Adapted bodies: none declared.
// TESEffectShader, TESEffectShader::InitializeData, ::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESEffectShader::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 13, RVA 0x26b760
// EffectShaderData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); size 0x1A0 from NG
// EffectShaderData::Initialize: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); the callee at RVA 0x26ab40 that InitializeData tail-calls with this + 0x20 (name only)
// EffectShaderData::unk00: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares a uint32, here an opaque block standing for the data members
// TESEffectShader::unk1C0: GUESS(low); the members after data are not recovered
#pragma once

#include <cstdint>

#include "TESForm.h"

// fillTextureEffectAlphaFadeInTime, fillTextureEffectFullAlphaTime, fillTextureEffectAlphaFadeOutTime, edgeEffectAlphaFadeInTime,
// edgeEffectFullAlphaTime, edgeEffectAlphaFadeOutTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk20, unk48: GUESS(low); the members around the fill and edge timings are not recovered here
class EffectShaderData {
public:
    void Initialize();

    std::uint8_t unk00[0x14];                    // 00
    float fillTextureEffectAlphaFadeInTime;      // 14
    float fillTextureEffectFullAlphaTime;        // 18
    float fillTextureEffectAlphaFadeOutTime;     // 1C
    std::uint8_t unk20[0x1C];                    // 20
    float edgeEffectAlphaFadeInTime;             // 3C
    float edgeEffectFullAlphaTime;               // 40
    float edgeEffectAlphaFadeOutTime;            // 44
    std::uint8_t unk48[0x1A0 - 0x48];            // 48
};
static_assert(sizeof(EffectShaderData) == 0x1A0, "layout");

class TESEffectShader : public TESForm {
public:
    void InitializeData() override;  // 04
    void InitItemImpl() override;    // 13
    // GetTotalDuration, GetFadeInAndFullDuration: GUESS(low); the longer of the edge and fill effect timings
    float GetTotalDuration() const;
    float GetFadeInAndFullDuration() const;

    EffectShaderData data;           // 20
    std::uint8_t     unk1C0[0x60];   // 1C0
};
static_assert(sizeof(TESEffectShader) == 0x220, "layout");

// GetCompileIndexForOwner and the other callees below: GUESS(low); declared without bodies, bound by RVA in bind-hints.json.
std::uint64_t GetCompileIndexForOwner(TESEffectShader* a_owner, std::uint32_t a_mask);                  // RVA 0x1e5ae0
void          RecordFlags_AddCompileIndex(std::uint32_t* a_formID, std::uint64_t a_compileIndex);       // RVA 0x1e6d00
TESForm*      GetFormForID(std::uint32_t a_formID);                                                      // RVA 0x1e5860
void*         LoadFormForID(std::uint32_t a_formID);                                                     // RVA 0x559a10
void          FinishInitItem(TESEffectShader* a_owner, bool a_flag);                                     // RVA 0x1e60b0
