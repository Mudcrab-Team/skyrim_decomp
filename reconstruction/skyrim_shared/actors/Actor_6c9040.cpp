// Actor: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Actor, CombatGroup, GetCombatGroup: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FindGroupActor, FindMember: GUESS(medium); callee returns an actor-like pointer; exact semantics unknown.
// UnknownSlot: STANDIN GUESS(low); unclaimed virtual slots preserve only target slot position.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6c9040 FindGroupActor
#include "Actor_6c9040.h"
namespace P2073 {
Actor* Actor::FindGroupActor() {
    CombatGroup* group = GetCombatGroup();
    return group ? group->FindMember() : nullptr;
}
}
