// Source exposure: mixed (pinned image listings, project ActorProcess units and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstructions from the pinned listings with the adaptations below.
// Adapted bodies: IsArrested and ClearActionHeadtrackTarget follow CommonLibSSE-NG@b93280e src/RE/A/AIProcess.cpp (MIT).
// 0x6f5120 ActorProcess::IsInCommandState
// 0x6f5140 ActorProcess::Function6f5140
// 0x6f5160 ActorProcess::Function6f5160
// 0x6f5180 ActorProcess::IsTalkingToPlayer
// 0x6f51a0 ActorProcess::SetTalkingToPlayer
// 0x6f51c0 ActorProcess::Function6f51c0
// 0x6f51e0 ActorProcess::Function6f51e0
// 0x6f5200 ActorProcess::SetBreathTimer
// 0x6f5250 ActorProcess::IsGreetingPlayer
// 0x6f5270 ActorProcess::SetGreetingPlayer
// 0x6f52b0 ActorProcess::SetSoundDelay
// 0x6f5500 ActorProcess::SetIdleTimer
// 0x6f5e20 ActorProcess::Function6f5e20
// 0x6f5e80 ActorProcess::Function6f5e80
// 0x6f5ea0 ActorProcess::Function6f5ea0
// 0x6f60c0 ActorProcess::Function6f60c0
// 0x6f6360 ActorProcess::SetPlantedExplosiveFlag
// 0x6f6380 ActorProcess::HasPlantedExplosiveFlag
// 0x6f63a0 ActorProcess::HasStartedAggroRadius
// 0x6f63c0 ActorProcess::SetAggroRadiusStarted
// 0x6f6400 ActorProcess::SetDualCasting
// 0x6f6470 ActorProcess::Function6f6470
// 0x6f6670 ActorProcess::Function6f6670
// 0x6f6dc0 ActorProcess::Function6f6dc0
// 0x6f6f80 ActorProcess::Function6f6f80
// 0x6f6fa0 ActorProcess::GetGreetingTimer
// 0x6f6fc0 ActorProcess::SetGreetingTimer
// 0x6f6fe0 ActorProcess::GetLastGreeting
// 0x6f7000 ActorProcess::SetLastGreeting
// 0x6f7020 ActorProcess::GetExclusiveTimer
// 0x6f7040 ActorProcess::SetExclusiveTimer
// 0x6fdd80 ActorProcess::IsArrested
// 0x6fde10 ActorProcess::SetBumpState
// 0x6fde30 ActorProcess::GetBumpState
// 0x6fde50 ActorProcess::Function6fde50
// 0x6fe000 ActorProcess::GetFadeState
// 0x6fe690 ActorProcess::SetDefaultHeadtrackTarget
// 0x6fe6b0 ActorProcess::Function6fe6b0
// 0x6fe6d0 ActorProcess::SetScriptHeadtrackTarget
// 0x6fe6f0 ActorProcess::SetCombatHeadtrackTarget
// 0x6fe710 ActorProcess::SetDialogueHeadtrackTarget
// 0x6fe730 ActorProcess::SetProcedureHeadtrackTarget
// 0x6fe7a0 ActorProcess::ClearActionHeadtrackTarget
// 0x6ff470 ActorProcess::GetLightLevel
// 0x6ff490 ActorProcess::SetLightLevel
// 0x6ff4e0 ActorProcess::SetPathLookAtTarget
#include "ActorProcess_6f5120.h"

// defaultField3B8, resetTimeStamp: STANDIN GUESS(low)
extern const AddressedField defaultField3B8;
extern const float resetTimeStamp;

bool ActorProcess::IsInCommandState() const
{
    return high && high->inCommandState;
}

std::uint64_t ActorProcess::Function6f5140() const
{
    return high ? high->unk358 : 0;
}

void ActorProcess::Function6f5160(std::uint64_t value)
{
    if (high) {
        high->unk358 = value;
    }
}

bool ActorProcess::IsTalkingToPlayer() const
{
    return high && high->talkingToPC;
}

void ActorProcess::SetTalkingToPlayer(bool value)
{
    if (high) {
        high->talkingToPC = value;
    }
}

std::uint32_t ActorProcess::Function6f51c0() const
{
    return high ? high->unk368 : 0;
}

void ActorProcess::Function6f51e0(std::uint32_t value)
{
    if (high) {
        high->unk368 = value;
    }
}

void ActorProcess::SetBreathTimer(float value)
{
    if (high) {
        high->breathTimer = value;
    }
}

bool ActorProcess::IsGreetingPlayer() const
{
    return high && high->greetingPlayer;
}

void ActorProcess::SetGreetingPlayer(bool value)
{
    if (high) {
        high->greetingPlayer = value;
    }
}

void ActorProcess::SetSoundDelay(float value)
{
    if (high) {
        high->soundDelay = value;
    }
}

void ActorProcess::SetIdleTimer(float value)
{
    if (high) {
        high->idleTimer = value;
    }
}

void ActorProcess::Function6f5e20(float value)
{
    if (high) {
        high->unk2A4 = value;
    }
}

float ActorProcess::Function6f5e80() const
{
    return high ? high->value2AC : 0.0f;
}

void ActorProcess::Function6f5ea0(float value)
{
    if (high) {
        high->value2AC = value;
    }
}

const AddressedField* ActorProcess::Function6f60c0() const
{
    if (high) {
        return &high->field3B8;
    }
    return &defaultField3B8;
}

void ActorProcess::SetPlantedExplosiveFlag(bool value)
{
    if (high) {
        high->getPlantedExplosive = value;
    }
}

bool ActorProcess::HasPlantedExplosiveFlag() const
{
    return high && high->getPlantedExplosive;
}

bool ActorProcess::HasStartedAggroRadius() const
{
    return high ? high->aggroRadiusStarted : false;
}

void ActorProcess::SetAggroRadiusStarted(bool value)
{
    if (high) {
        high->aggroRadiusStarted = value;
    }
}

void ActorProcess::SetDualCasting(bool value)
{
    if (high) {
        high->isDualCasting = value;
    }
}

std::int32_t ActorProcess::Function6f6470() const
{
    return high ? high->actionIndex : -1;
}

void ActorProcess::Function6f6670(std::uint16_t value)
{
    if (high) {
        high->counter448 += value;
    }
}

void ActorProcess::Function6f6dc0()
{
    if (high) {
        high->unk45C = 0;
    }
}

void ActorProcess::Function6f6f80()
{
    if (high) {
        high->value3EC = -1.0f;
    }
}

float ActorProcess::GetGreetingTimer() const
{
    return high ? high->greetingTimer : 0.0f;
}

void ActorProcess::SetGreetingTimer(float value)
{
    if (high) {
        high->greetingTimer = value;
    }
}

TESTopicInfo* ActorProcess::GetLastGreeting() const
{
    return high ? high->lastGreeting : nullptr;
}

void ActorProcess::SetLastGreeting(TESTopicInfo* value)
{
    if (high) {
        high->lastGreeting = value;
    }
}

float ActorProcess::GetExclusiveTimer() const
{
    return high ? high->exclusiveTimer : 0.0f;
}

void ActorProcess::SetExclusiveTimer(float value)
{
    if (high) {
        high->exclusiveTimer = value;
    }
}

bool ActorProcess::IsArrested() const
{
    return high && high->arrested;
}

void ActorProcess::SetBumpState(HighProcessData::BUMP_TYPE value)
{
    if (high) {
        high->bumpedState = value;
    }
}

HighProcessData::BUMP_TYPE ActorProcess::GetBumpState() const
{
    return high ? high->bumpedState : HighProcessData::BUMP_TYPE::kNone;
}

void ActorProcess::Function6fde50()
{
    if (high) {
        high->timeStampValue = resetTimeStamp;
    }
}

HighProcessData::FADE_STATE ActorProcess::GetFadeState() const
{
    return high ? high->fadeState : HighProcessData::FADE_STATE::kNormal;
}

void ActorProcess::SetDefaultHeadtrackTarget(TESObjectREFR* target)
{
    if (high) {
        high->SetHeadtrackTarget(HighProcessData::kDefault, target);
    }
}

void ActorProcess::Function6fe6b0(void* target)
{
    if (high) {
        high->Function71f9c0(HighProcessData::kAction, target);
    }
}

void ActorProcess::SetScriptHeadtrackTarget(TESObjectREFR* target)
{
    if (high) {
        high->SetHeadtrackTarget(HighProcessData::kScript, target);
    }
}

void ActorProcess::SetCombatHeadtrackTarget(TESObjectREFR* target)
{
    if (high) {
        high->SetHeadtrackTarget(HighProcessData::kCombat, target);
    }
}

void ActorProcess::SetDialogueHeadtrackTarget(TESObjectREFR* target)
{
    if (high) {
        high->SetHeadtrackTarget(HighProcessData::kDialogue, target);
    }
}

void ActorProcess::SetProcedureHeadtrackTarget(TESObjectREFR* target)
{
    if (high) {
        high->SetHeadtrackTarget(HighProcessData::kProcedure, target);
    }
}

void ActorProcess::ClearActionHeadtrackTarget(bool defaultHold)
{
    if (high) {
        high->ClearHeadtrackTarget(HighProcessData::kAction, defaultHold);
    }
}

float ActorProcess::GetLightLevel() const
{
    return high ? high->lightLevel : 0.0f;
}

void ActorProcess::SetLightLevel(float value)
{
    if (high) {
        high->lightLevel = value;
    }
}

void ActorProcess::SetPathLookAtTarget(const ObjectRefHandle& value)
{
    if (high) {
        high->pathLookAtTarget = value;
    }
}
