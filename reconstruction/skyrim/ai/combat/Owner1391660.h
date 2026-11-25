// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_1391660, Function1391660, Owner1391660: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Owner1391660 : public NiRefObject
{
public:
    ~Owner1391660() override;  // 00
    BGSAttackData* Function1391660(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Owner1391660) == 0x48, "Owner1391660 size");
static_assert(offsetof(Owner1391660, attackDataMap) == 0x10, "Owner1391660 members");
