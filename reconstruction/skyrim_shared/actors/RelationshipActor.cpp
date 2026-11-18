// ScriptRelationshipPass: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xa00a60 P2071::HighestRank
// 0xa00bd0 P2071::LowestRank
#include "RelationshipActor.h"
namespace P2071 {
int HighestRank(void*, unsigned, RelationshipActor* actor) {
    auto* relation = Highest(actor->reference.data.objectReference);
    return relation ? RankValues[RankIndex(relation)] : 0;
}
int LowestRank(void*, unsigned, RelationshipActor* actor) {
    auto* relation = Lowest(actor->reference.data.objectReference);
    return relation ? RankValues[RankIndex(relation)] : 0;
}
}
