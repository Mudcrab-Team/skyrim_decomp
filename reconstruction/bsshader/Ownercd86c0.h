// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: declarations written for this reconstruction; names from the community headers below. Stamped as a twin of matched 0x157ed10 (bsshader/BSShadowDirectionalLight): source copied, names replaced by placeholders.
// src/RE/N/NiPoint3.cpp, MIT; component-wise copy, notice in the SPDX line below).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// fSunShadowUpdateTime: GUESS(low)
// Ownercd86c0: GUESS(low) STANDIN
// BSShadowLight, unknown578, targetDirection, fromDirection, blendTimer, cameraMoved, UpdateSunDirectionBlend, GetIsFrustumOrDirectionalLight, GetIsDirectionalLight, GetNeedsClipPlanes: GUESS(low) STANDIN
#pragma once
#include "BSShadowDirectionalLight.h"

class Ownercd86c0 : public BSShadowLight
{
public:
    virtual std::uint32_t GetPassExtraParam(std::uint32_t a_accumFlag);
    virtual bool GetIsFrustumOrDirectionalLight();
    virtual bool GetIsDirectionalLight();
    virtual bool GetNeedsClipPlanes();

    // Blends the sun direction towards a new target over fSunShadowUpdateTime seconds.
    void UpdateSunDirectionBlend(NiPoint3* a_direction, std::int32_t a_previousCameraMoved);

    NiPoint3 targetDirection;       // 560
    NiPoint3 fromDirection;         // 56C
    std::uint8_t unknown578[0x38];  // 578
    float blendTimer;               // 5B0
    std::uint32_t cameraMoved;      // 5B4
};
static_assert(sizeof(Ownercd86c0) == 0x5B8, "Ownercd86c0 size");
