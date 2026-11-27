// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectARMA, TESObjectARMA::ClearData, TESObjectARMA::bipedModels, TESObjectARMA::bipedModel1stPersons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESModelTextureSwap, TESModelTextureSwap::~TESModelTextureSwap, TESModelTextureSwap::InitializeDataComponent, TESModelTextureSwap::ClearDataComponent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectARMA::unknown00, TESModelTextureSwap::unknown08: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>

class TESModelTextureSwap
{
public:
    virtual ~TESModelTextureSwap();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    std::uint8_t unknown08[0x30];
};
static_assert(sizeof(TESModelTextureSwap) == 0x38, "community component stride");
class TESObjectARMA
{
public:
    void ClearData();
    std::uint8_t unknown00[0x50];
    TESModelTextureSwap bipedModels[2];
    TESModelTextureSwap bipedModel1stPersons[2];
};
static_assert(offsetof(TESObjectARMA, bipedModels) == 0x50, "community model offset");
static_assert(offsetof(TESObjectARMA, bipedModel1stPersons) == 0xC0, "community first-person offset");
