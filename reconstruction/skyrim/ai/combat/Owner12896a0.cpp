// Code origin: hand-written from the local listing; names and declarations from the community header named in BGSAttackDataMap.h. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x12896a0 Owner12896a0::Function12896a0
#include "Owner12896a0.h"

// FindAttackData_12896a0: GUESS(low) STANDIN
BGSAttackData* FindAttackData_12896a0(BSTHashMapAttackData& a_map, const BSFixedString& a_event);

// guess: same compiled code as matched 0x44ab10 apart from relocated fields; its role here is not established.
BGSAttackData* Owner12896a0::Function12896a0(const BSFixedString& a_event)
{
    return FindAttackData_12896a0(attackDataMap, a_event);
}
