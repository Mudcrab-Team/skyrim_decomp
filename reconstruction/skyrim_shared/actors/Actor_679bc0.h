// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, Actor::ResetHealthAndLimbs: CRASHLOGGER_PDB(59818@2026.10.24)
// TESDataHandler, ActorValue, ActorValue::kHealth, ACTOR_VALUE_MODIFIER, ACTOR_VALUE_MODIFIER::kDamage: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetActorValueModifier, Actor::RestoreActorValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESDataHandler::singleton, TESDataHandler::IsLoading, kHealthResetTarget: GUESS(low)
#pragma once

#include <cstdint>

extern const float kHealthResetTarget;

enum class ActorValue : std::int32_t
{
    kHealth = 24,
};

enum class ACTOR_VALUE_MODIFIER : std::int32_t
{
    kDamage = 2,
};

class TESDataHandler
{
public:
    static TESDataHandler* singleton;

    bool IsLoading() const;
};

class Actor
{
public:
    float GetActorValueModifier(ACTOR_VALUE_MODIFIER a_modifier, ActorValue a_value) const;
    void  RestoreActorValue(ActorValue a_value, float a_amount);
    void  ResetHealthAndLimbs();
};
