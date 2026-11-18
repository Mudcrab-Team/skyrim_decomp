// Code origin: hand-written from the local listing; names and declarations from the community header named in BGSAttackDataMap.h.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x44ab10 BGSAttackDataMap::GetAttackData
#include "BGSAttackDataMap.h"

// FindAttackData: STANDIN GUESS(low); the hash-map lookup at address 0x44b0a0, called on the map member
BGSAttackData* FindAttackData(BSTHashMapAttackData& a_map, const BSFixedString& a_event);

BGSAttackData* BGSAttackDataMap::GetAttackData(const BSFixedString& a_event)
{
    return FindAttackData(attackDataMap, a_event);
}
