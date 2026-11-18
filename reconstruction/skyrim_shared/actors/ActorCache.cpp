// ActorCache: STANDIN GUESS(low); target-bound partial receiver and callee views; original names remain hypotheses.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Origin: original reconstruction; adapted declarations retain their cited source notices.
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x69d120 P2071::ActorCache::InvalidateCache
#include "ActorCache.h"
namespace P2071 {
void ActorCache::InvalidateCache() {
    ApplyFlag(true);
    Refresh();
    if (currentProcess && currentProcess->cachedValues) currentProcess->cachedValues->flags &= ~0x08000000u;
}
}
