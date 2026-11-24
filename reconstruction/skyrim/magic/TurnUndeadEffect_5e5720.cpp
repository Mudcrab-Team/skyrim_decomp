// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below; callees checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/TargetValueModifierEffect.cpp:41
// 0x5e5720 TurnUndeadEffect::CheckTarget
#include "TurnUndeadEffect_5e5720.h"

// The generic target check must pass and the target must actually be undead.
bool TurnUndeadEffect::CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args)
{
    bool result = TargetValueModifierEffect::CheckTarget(a_args);
    if (result) {
        Actor* actor = a_args.pTarget->GetTargetAsActor();
        if (actor && actor->IsUndead()) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}
