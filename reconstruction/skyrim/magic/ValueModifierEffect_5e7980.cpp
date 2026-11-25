// Source exposure: mixed (community declarations, authorized sibling game code, pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5e7980 ValueModifierEffect::Function5e7980
// Adapted bodies: none
#include "ValueModifierEffect_5e7980.h"
// Tests the actor state required by the selected actor value.
bool ValueModifierEffect::Function5e7980()
{
    Actor* actor = target->GetTargetAsActor();
    switch (actorValue) {
    case 39:
    case 63:
        return actor->vtable->IsInCombat(actor);
    case 57:
        return (actor->stateFlags >> 18) & 1;
    default:
        return true;
    }
}
