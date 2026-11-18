// ArrestProcess: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed, target pack and public community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
namespace P2071 {
// ArrestProcess: STANDIN GUESS(medium); partial process view, no ownership or layout asserted.
// IsArrested: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class ArrestProcess { public: bool IsArrested() const; };
// ArrestActor: STANDIN GUESS(medium); prefix and process pointer used by target.
using ArrestActor = P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, ArrestProcess>;
// PapyrusIsArrested: GUESS(medium); scripting argument types and original name unverified.
bool PapyrusIsArrested(void*, unsigned, ArrestActor* actor);
}
