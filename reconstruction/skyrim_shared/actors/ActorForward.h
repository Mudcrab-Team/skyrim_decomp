// Source exposure: mixed; Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; types adapted from pinned public MIT declarations.
// ActorForward: STANDIN GUESS(medium); partial research declaration, not a recovered original name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "skyrim_shared/actors/ActorTargetPrefix.h"
#include "../../gamebryo/nimain/NiPoint3.h"
namespace P207SolRetry {
// ActorForward: STANDIN GUESS(medium); typed actor receiver prefix; ordinary owner inferred.
class ActorForward : public P206Target::ActorTargetPrefix<> {
public:
    // ResolveController: GUESS(medium); direct helper returns actor-associated movement receiver.
    MovementControllerNPC* ResolveController();
    // ForwardValues: GUESS(low); forwards point and three floats, semantics unconfirmed.
    void ForwardValues(const NiPoint3&, float, float, float);
};
}
