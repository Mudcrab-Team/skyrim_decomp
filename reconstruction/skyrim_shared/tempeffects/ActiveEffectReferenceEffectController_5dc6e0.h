// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController, ActiveEffect, EffectSetting, effect, GetBaseObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetScale, flags, dualCastScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsHitEffectArtScaleOverridden: SIBLING(fo4-private@1b765c70, author-permission)
// Minimal stand-ins flatten accessed nested fields at their observed offsets.
#pragma once
#include <cstddef>
class EffectSetting {
public:
    bool IsHitEffectArtScaleOverridden() const;
    unsigned char unknown00[0x110];
    float dualCastScale;
};
class ActiveEffect {
public:
    EffectSetting* GetBaseObject() noexcept;
    unsigned char unknown00[0x7c];
    unsigned flags;
};
class ActiveEffectReferenceEffectController {
public:
    float GetScale();
    unsigned char unknown00[8];
    ActiveEffect* effect;
};
static_assert(offsetof(EffectSetting, dualCastScale) == 0x110, "accessed field offset");
static_assert(offsetof(ActiveEffect, flags) == 0x7c, "accessed field offset");
static_assert(offsetof(ActiveEffectReferenceEffectController, effect) == 8, "accessed field offset");
