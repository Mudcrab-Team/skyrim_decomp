// Source exposure: mixed (community declarations, community PDB names, and local binary analysis).
// Code origin: original handwritten reconstruction from the assigned local listing; minimal declarations use cited name and layout sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueOwner::GetUnarmedDamage: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner, ActorValueOwner::~ActorValueOwner, ActorValueOwner::GetActorValue, ActorValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValue::kUnarmedDamage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

enum class ActorValue : std::int32_t
{
    kUnarmedDamage = 35
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(ActorValue value);

    static void GetUnarmedDamage(ActorValueOwner* owner, float& damage);
};
