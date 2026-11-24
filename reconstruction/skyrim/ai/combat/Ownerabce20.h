// Code origin: hand-written class layout and declarations adapted from the CharmedBaryon/CommonLibSSE-NG headers named below; the compared body is written from the local listing. Stamped as a twin of matched 0x44ab10 (skyrim/ai/combat/BGSAttackDataMap): source copied, names replaced by placeholders.
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAttackData, BSFixedString, TESRace: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FindAttackData_abce20, Functionabce20, Ownerabce20: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataMap.h"

class Ownerabce20 : public NiRefObject
{
public:
    ~Ownerabce20() override;  // 00
    BGSAttackData* Functionabce20(const BSFixedString& a_event);

    BSTHashMapAttackData attackDataMap;  // 10
    TESRace* defaultDataRace;  // 40
};
static_assert(sizeof(Ownerabce20) == 0x48, "Ownerabce20 size");
static_assert(offsetof(Ownerabce20, attackDataMap) == 0x10, "Ownerabce20 members");
