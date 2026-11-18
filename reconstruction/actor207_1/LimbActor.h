// LimbActor: STANDIN GUESS(low); partial target-bound receiver/callee view, no complete layout or ownership asserted.
// Origin: original reconstruction; cited adapted declarations retain complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md. Prefix adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
#include <cstdint>
namespace P2071 {
// LimbActor: STANDIN GUESS(medium); partial actor receiver.
class LimbActor : public P206Target::ActorTargetPrefix<> { public:
    // IsLimbGone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
    bool IsLimbGone(std::uint32_t);
};
// LimbData: STANDIN GUESS(low); helper result identity unknown.
class LimbData;
// FindLimbData, CheckLimb: GUESS(low); helper signatures and meaning inferred.
LimbData* FindLimbData(P206Target::ExtraDataListPrefix*);
bool CheckLimb(LimbData*, std::uint32_t);
}
