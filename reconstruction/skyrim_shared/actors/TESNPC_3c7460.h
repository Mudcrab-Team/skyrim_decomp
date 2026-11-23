// Source exposure: mixed (community headers and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, ActorValueOwner, ActorValueOwner::SetBaseActorValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESNPC::SetSkillOrBaseActorValue, ActorValueOwner::unk01, ActorValueOwner::unk02, ActorValueOwner::unk03, TESNPC::actorValues, TESNPC::unk08, TESNPC::unkA8: GUESS(low)

#pragma once

#include "declarations/TESForm.h"
#include <cstddef>

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void SetBaseActorValue(std::int32_t a_actorValue, float a_value);
};

class TESNPC
{
public:
    void SetSkillOrBaseActorValue(std::int32_t a_actorValue, float a_value);

    ActorValueOwner actorValues;
    std::uint8_t unk08[0xA0];
    std::uint8_t unkA8[18];
};
