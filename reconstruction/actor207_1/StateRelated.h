// StateRelated: STANDIN GUESS(low); incomplete target-bound view; original identity and ownership unproved.
// Origin: original reconstruction with cited adapted declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
namespace P2071 {
// StateActor: STANDIN GUESS(low); ordinary receiver identity uncertain.
using StateActor = P206Target::ActorTargetPrefix<>;
// StateRelated: STANDIN GUESS(low); related helper receiver has unknown layout.
class StateRelated { public:
    // Test: GUESS(low); direct callee identity unknown.
    bool Test();
};
// Related, TestState, QueryActorState: GUESS(low); helper and function identities inferred.
StateRelated* Related(StateActor*);
bool TestState(P206Target::ActorStatePrefix*);
bool QueryActorState(StateActor*);
}
