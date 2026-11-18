// StateRelated: STANDIN GUESS(low); incomplete target-bound view; original identity and ownership unproved.
// Origin: original reconstruction with cited adapted declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6a6be0 P2071::QueryActorState
#include "StateRelated.h"
namespace P2071 {
bool QueryActorState(StateActor* actor) {
    return !Related(actor)->Test() || TestState(&actor->actorState);
}
}
