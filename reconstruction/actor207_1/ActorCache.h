// ActorCache: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorValueTargetPrefix.h"
namespace P2071 {
// ActorCache: STANDIN GUESS(medium); partial actor receiver.
class ActorCache : public P206Target::ActorTargetPrefix<P206Target::ExtraDataListPrefix, P206Target::AIProcessTargetPrefix> { public:
    // ApplyFlag, Refresh, InvalidateCache: GUESS(low); effect-based names and helper signatures inferred.
    void ApplyFlag(bool);
    void Refresh();
    void InvalidateCache();
};
}
