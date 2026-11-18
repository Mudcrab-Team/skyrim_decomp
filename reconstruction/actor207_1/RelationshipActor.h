// ScriptRelationshipPass: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; drafted by gpt-6.1-terra.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include "actors/ActorTargetPrefix.h"
#include <cstdint>
namespace P2071 {
// RelationshipActor, Relationship: STANDIN GUESS(low); incomplete actor and relationship views.
// Represents the already-bound actor prefix only; complete allocation and ownership are unknown.
class RelationshipActor : public P206Target::ActorTargetPrefix<> {};
class Relationship;
// Highest, Lowest, RankIndex, FindRelation, IsFamily, HasAnyFamily, RankValues: GUESS(low); helper contracts and semantics inferred.
Relationship* Highest(P206Target::TESBoundObject*);
Relationship* Lowest(P206Target::TESBoundObject*);
int RankIndex(Relationship*);
Relationship* FindRelation(P206Target::TESBoundObject*, P206Target::TESBoundObject*);
bool IsFamily(Relationship*);
bool HasAnyFamily(P206Target::TESBoundObject*);
extern int RankValues[];
// HighestRank, LowestRank, FamilyRelationship: GUESS(low); scripting signatures inferred.
int HighestRank(void*, unsigned, RelationshipActor*);
int LowestRank(void*, unsigned, RelationshipActor*);
bool FamilyRelationship(void*, unsigned, RelationshipActor*, RelationshipActor*);
}
