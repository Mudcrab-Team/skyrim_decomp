// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_12896a0, Function12896a0, Owner12896a0: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Owner12896a0 : public NiRefObject
{
public:
    ~Owner12896a0() override;  // 00
    BGSAttackData* Function12896a0(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Owner12896a0) == 0x48, "Owner12896a0 size");
static_assert(offsetof(Owner12896a0, attackDataMap) == 0x10, "Owner12896a0 members");
