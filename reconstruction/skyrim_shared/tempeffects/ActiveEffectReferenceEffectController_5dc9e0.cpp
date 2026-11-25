// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// 0x5dc9e0 ActiveEffectReferenceEffectController::EffectShouldFaceTarget
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController, ActiveEffect, EffectSetting, effect, GetBaseObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectShouldFaceTarget, BGSReferenceEffect, hitVisuals, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted body: EffectShouldFaceTarget, fo4-private@1b765c70, author-permission; target field offsets and community accessor names.
// EffectShouldFaceTarget: SIBLING(fo4-private@1b765c70, author-permission); body adapted below.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:289
#include "ActiveEffectReferenceEffectController_5dc9e0.h"

bool ActiveEffectReferenceEffectController::EffectShouldFaceTarget()
{
    return effect && effect->GetBaseObject() &&
        effect->GetBaseObject()->hitVisuals &&
        (effect->GetBaseObject()->hitVisuals->flags & 1) != 0;
}
