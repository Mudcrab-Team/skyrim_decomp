// Near miss: 3.0 alignment distance | control-flow
// Code origin: adapted sibling body; stand-in declarations from CommonLibSSE-NG.
// 0x64d060 EnhanceWeaponEffect::ClearTargetImpl
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EnhanceWeaponEffect, ClearTargetImpl, Revert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect, ValueModifierEffect, MagicTarget, GetTargetAsActor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor, AIProcess, currentProcess, target: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTEventSink, ActorInventoryEvent, BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterActorInventoryEventSink: SIBLING(fo4-private@1b765c70, author-permission)
// inventoryEventSink: GUESS(low); names the event-sink subobject
// unknownPrefix, unknownTail, vtable: OBSERVED
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:12
#include "include/64d060/EnhanceWeaponEffect_64d060.h"

void EnhanceWeaponEffect::ClearTargetImpl()
{
    Actor* actor = target ? target->GetTargetAsActor() : nullptr;
    AIProcess* process = actor ? actor->currentProcess : nullptr;
    if (process)
        process->UnregisterActorInventoryEventSink(&inventoryEventSink);
    ValueModifierEffect::ClearTargetImpl();
}
