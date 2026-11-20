// ForwardTarget: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: binary-analysis; drafted by gpt-6.1-terra.
// 0x6a6a00 P2071::ActorForwardPredicate
#include "ForwardTarget.h"
namespace P2071 {
bool ActorForwardPredicate(ActorForwardInput* actor) {
    auto* target = GetForwardTarget(actor);
    return target->PredicateA() && !target->PredicateB();
}
}
