// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below; callees checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReanimateEffect.cpp:21
// 0x5dada0 ReanimateEffect::CheckTarget
#include "ReanimateEffect_5dada0.h"

// Only a target actor that can be raised and whose level fits the magnitude is a valid victim.
bool ReanimateEffect::CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args)
{
    MagicTarget* magicTarget = a_args.pTarget;
    if (magicTarget) {
        Actor* actor = magicTarget->GetTargetAsActor();
        if (actor) {
            if (MagicUtilities::CanBeReanimated(*actor)) {
                if (ActiveEffectFactory::CheckTargetLevelMagnitude(actor->GetLevel(), a_args)) {
                    return true;
                }
            }
        }
    }
    return false;
}
