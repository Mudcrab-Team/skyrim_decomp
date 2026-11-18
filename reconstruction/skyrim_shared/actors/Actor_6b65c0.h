// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Actor, Actor::ShouldPerformRevert: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Actor::ConditionOne, Actor::ConditionTwo, Actor::GetArrestContext, Actor::ApplyArrestState, papyrus::Actor::SetPlayerResistingArrest: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class Actor {
public:
 bool ShouldPerformRevert() const;
 bool ConditionOne() const;
 bool ConditionTwo() const;
 void* GetArrestContext();
 void ApplyArrestState(bool, void*);
};

namespace papyrus { namespace Actor { void SetPlayerResistingArrest(void*, unsigned int, ::Actor*); } }
