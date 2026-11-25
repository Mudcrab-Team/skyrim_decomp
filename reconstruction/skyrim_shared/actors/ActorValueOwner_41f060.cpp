// Source exposure: mixed (community declarations, community PDB names, and local binary analysis).
// Code origin: original handwritten reconstruction from the assigned local listing; minimal declarations use cited name and layout sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x41f060 ActorValueOwner::GetUnarmedDamage
#include "ActorValueOwner_41f060.h"

void ActorValueOwner::GetUnarmedDamage(ActorValueOwner* owner, float& damage)
{
    float value = 0.0f;
    if (owner) {
        value = owner->GetActorValue(ActorValue::kUnarmedDamage);
    }
    damage = value;
}
