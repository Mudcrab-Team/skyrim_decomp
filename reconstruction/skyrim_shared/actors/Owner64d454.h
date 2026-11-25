// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial base declarations follow CommonLibSSE-NG and the offsets observed in the thunks. Stamped as a twin of matched 0x3cba24 (skyrim_shared/actors/TESNPC_3cba60): source copied, names replaced by placeholders.
// TESBoundAnimObject, TESActorBaseData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESContainer, TESSpellList, TESAIForm, TESFullName, ActorValueOwner: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSDestructibleObjectForm, BGSSkinForm, BGSKeywordForm, BGSAttackDataForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner64d454: GUESS(low) STANDIN
// BGSPerkRankArray: GUESS(low) STANDIN
#pragma once
#include "TESNPC_3cba60.h"

class Owner64d454 :
    public TESBoundAnimObject,
    public TESActorBaseData,
    public TESContainer,
    public TESSpellList,
    public TESAIForm,
    public TESFullName,
    public ActorValueOwner,
    public BGSDestructibleObjectForm,
    public BGSSkinForm,
    public BGSKeywordForm,
    public BGSAttackDataForm,
    public BGSPerkRankArray
{
public:
    Owner64d454();
    ~Owner64d454() override;
};
static_assert(sizeof(Owner64d454) == 0x150, "Owner64d454 size");
