// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// 0x5dc6e0 ActiveEffectReferenceEffectController::GetScale
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController, ActiveEffect, EffectSetting, effect, GetBaseObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetScale, flags, dualCastScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsHitEffectArtScaleOverridden: SIBLING(fo4-private@1b765c70, author-permission)
// Adapted body: GetScale, fo4-private@1b765c70, author-permission; target layout and community accessor names.
// GetScale: SIBLING(fo4-private@1b765c70, author-permission); body adapted below.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:219
#include "ActiveEffectReferenceEffectController_5dc6e0.h"

float ActiveEffectReferenceEffectController::GetScale()
{
    const bool dualCast = (effect->flags >> 12) & 1;
    if (dualCast) {
        if (!effect->GetBaseObject()->IsHitEffectArtScaleOverridden()) {
            return effect->GetBaseObject()->dualCastScale;
        }
    }
    return 1.0f;
}
