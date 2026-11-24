// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_b32cd0, Functionb32cd0, Ownerb32cd0: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Ownerb32cd0 : public NiRefObject
{
public:
    ~Ownerb32cd0() override;  // 00
    BGSAttackData* Functionb32cd0(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Ownerb32cd0) == 0x48, "Ownerb32cd0 size");
static_assert(offsetof(Ownerb32cd0, attackDataMap) == 0x10, "Ownerb32cd0 members");
