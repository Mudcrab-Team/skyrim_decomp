// Origin: declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a (MIT); body original.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// MagicCaster, State, StartChargeImpl, StartReadyImpl, sounds, desiredTarget, currentSpell, state, castingTimer, currentSpellCost, magnitudeOverride, nextTargetUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSTArray, BSSoundHandle, ObjectRefHandle, MagicItem, TESObjectREFR, Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ChangeState, UpdateNextTargetTime, GetTimeOffset: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d07b0 MagicCaster::Func4
// 0x5cd3f0 MagicCaster::Function5cd3f0
#include "MagicCaster_5cd3f0.h"
bool MagicCaster::StartChargeImpl() {
 state = State::kReady;
 StartReadyImpl();
 if (state == State::kReady) ChangeState(State::kUnk02);
 return true;
}

void MagicCaster::UpdateNextTargetTime() {
 const float timer = castingTimer;
 const float offset = GetTimeOffset();
 nextTargetUpdate = timer + offset;
}
