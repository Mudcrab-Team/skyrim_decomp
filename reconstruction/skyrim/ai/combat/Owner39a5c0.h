// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_39a5c0, Function39a5c0, Owner39a5c0: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Owner39a5c0 : public NiRefObject
{
public:
    ~Owner39a5c0() override;  // 00
    BGSAttackData* Function39a5c0(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Owner39a5c0) == 0x48, "Owner39a5c0 size");
static_assert(offsetof(Owner39a5c0, attackDataMap) == 0x10, "Owner39a5c0 members");
