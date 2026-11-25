// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController, ActiveEffect, EffectSetting, effect, GetBaseObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectShouldFaceTarget, BGSReferenceEffect, hitVisuals, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Minimal stand-ins flatten accessed nested fields at their observed offsets.
#pragma once
#include <cstddef>
class BGSReferenceEffect {
public:
    unsigned char unknown00[0x30];
    unsigned flags;
};
class EffectSetting {
public:
    unsigned char unknown00[0x120];
    BGSReferenceEffect* hitVisuals;
};
class ActiveEffect {
public:
    EffectSetting* GetBaseObject() noexcept;
};
class ActiveEffectReferenceEffectController {
public:
    bool EffectShouldFaceTarget();
    unsigned char unknown00[8];
    ActiveEffect* effect;
};
static_assert(offsetof(BGSReferenceEffect, flags) == 0x30, "accessed field offset");
static_assert(offsetof(EffectSetting, hitVisuals) == 0x120, "accessed field offset");
static_assert(offsetof(ActiveEffectReferenceEffectController, effect) == 8, "accessed field offset");
