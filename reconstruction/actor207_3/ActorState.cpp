// ActorState: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// PlayerReceiver, SetValue, Transition, stateWord, Unknown00: STANDIN GUESS(medium); names and states inferred; omitted virtual identities unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75e4a0 Transition
#include "ActorState.h"
namespace P2073 {
bool ActorState::Transition(std::uint32_t state) {
    stateWord = (stateWord & ~0x3c000u) | ((state & 15u) << 14);
    if (state == 0 || state == 3 || state == 7) {
        PlayerReceiver::FromActorState(this)->SetValue(0.0f);
    }
    return true;
}
}
