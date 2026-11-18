// ConditionalNotify: STANDIN GUESS(low); target-bound partial ABI view, original method spelling unknown.
// Source exposure: mixed (target access observations and public type declarations).
// Origin: original reconstruction; typed prefix declarations adapted under the source notice below.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Supporting declaration names: GUESS(low); descriptive spelling for independently bound callees.
// Prefix type names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorPrimaryTargetPrefix.h"
#include "actors/PlayerCharacterTargetMembers.h"
namespace P206Sol {
class ConditionalNotify : public P206Target::ActorPrimaryTargetPrefix { public: void Set(bool); };
void Notify(P206Target::BGSScene*,ConditionalNotify*,std::uint32_t,std::uint32_t);
}
