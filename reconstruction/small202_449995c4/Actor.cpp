// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Actor, Actor::ShouldPerformRevert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Actor::ConditionOne, Actor::ConditionTwo, Actor::GetArrestContext, Actor::ApplyArrestState, papyrus::Actor::SetPlayerResistingArrest: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6b65c0 Actor::ShouldPerformRevert
// 0xa028b0 papyrus::Actor::SetPlayerResistingArrest
#include "Actor.h"
bool Actor::ShouldPerformRevert() const {
 return !(ConditionOne() && ConditionTwo());
}

void papyrus::Actor::SetPlayerResistingArrest(void*, unsigned int, ::Actor* actor) {
 void* context = actor->GetArrestContext();
 actor->ApplyArrestState(true, context);
}
