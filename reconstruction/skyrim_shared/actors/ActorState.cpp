// Source exposure: mixed (pinned image listing and community declarations).
// Code origin: original reconstruction; existing Transition preserved.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x75e4a0 Transition
// 0x6e1ab0 P2073::ActorState::Function6e1ab0
#include "ActorState.h"
namespace P2073 {
bool ActorState::Transition(std::uint32_t state) {
    stateWord = (stateWord & ~0x3c000u) | ((state & 15u) << 14);
    if (state == 0 || state == 3 || state == 7) {
        PlayerReceiver::FromActorState(this)->SetValue(0.0f);
    }
    return true;
}

void ActorState::Function6e1ab0() {
    stateWord = 0u;
    stateWord2.talkingToPlayer = 0;
    stateWord2.forceRun = 0;
    stateWord2.forceSneak = 0;
    stateWord2.headTracking = 1;
    stateWord2.reanimating = 0;
    stateWord2.weaponState = 0;
    stateWord2.wantBlocking = 0;
    stateWord2.flightBlocked = 0;
    stateWord2.recoil = 0;
    stateWord2.allowFlying = 1;
    stateWord2.staggered = 0;
    stateWord2.unk14 = 0;
}
}
