// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_3e1bc0, Function3e1bc0, Owner3e1bc0: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Owner3e1bc0 : public NiRefObject
{
public:
    ~Owner3e1bc0() override;  // 00
    BGSAttackData* Function3e1bc0(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Owner3e1bc0) == 0x48, "Owner3e1bc0 size");
static_assert(offsetof(Owner3e1bc0, attackDataMap) == 0x10, "Owner3e1bc0 members");
