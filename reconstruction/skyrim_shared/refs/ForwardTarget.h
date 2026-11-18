// ForwardTarget: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: binary-analysis; drafted by gpt-6.1-terra.
#pragma once
namespace P2071 {
// ActorForwardInput, ActorForwardResult: STANDIN GUESS(low); no layout or ownership asserted.
class ActorForwardInput;
class ActorForwardResult;
// ForwardTarget: STANDIN GUESS(low); helper receiver identity unknown.
class ForwardTarget { public:
    // PredicateA, PredicateB, Forward: GUESS(low); direct callee signatures inferred.
    bool PredicateA();
    bool PredicateB();
    void Forward(ActorForwardResult*, float, float);
};
// GetForwardTarget, ActorForwardPredicate, ActorForwardValues: GUESS(low); owner and return types unconfirmed.
ForwardTarget* GetForwardTarget(ActorForwardInput*);
bool ActorForwardPredicate(ActorForwardInput*);
void ActorForwardValues(ActorForwardInput*, ActorForwardResult*, float, float);
}
