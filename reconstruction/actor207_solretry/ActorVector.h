// Source exposure: mixed; Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; types adapted from pinned public MIT declarations.
// ActorVector: STANDIN GUESS(medium); partial research declaration, not a recovered original name.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
#include "NiPoint3.h"
namespace P207SolRetry {
// ActorVector: STANDIN GUESS(medium); typed actor receiver prefix; ordinary owner inferred.
class ActorVector : public P206Target::ActorTargetPrefix<> {
public:
    // ResolveController: GUESS(medium); direct helper returns actor-associated movement receiver.
    MovementControllerNPC* ResolveController();
    // ReadVector: GUESS(medium); hidden result pointer inferred from three-float result stores.
    NiPoint3 ReadVector();
};
// VectorX, VectorY, VectorZ: GUESS(low); three external float components, meaning unknown.
extern float VectorX, VectorY, VectorZ;
}
