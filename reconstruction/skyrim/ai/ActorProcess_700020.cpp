// Source exposure: mixed (pinned image listings, project ActorProcess units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstructions from the pinned listings, with cited adaptations.
// Adapted bodies: ClearAttackData uses the final-release rule in CommonLibSSE-NG@b93280e src/RE/N/NiRefObject.cpp (MIT).
// 0x700020 ActorProcess::GetVoiceState
// 0x700040 ActorProcess::SetVoiceState
// 0x700060 ActorProcess::GetCurrentShout
// 0x700080 ActorProcess::GetCurrentShoutVariation
// 0x7000a0 ActorProcess::SetCurrentShoutVariation
// 0x7000c0 ActorProcess::GetVoiceTimeElapsed
// 0x7000e0 ActorProcess::SetVoiceTimeElapsed
// 0x700120 ActorProcess::SetVoiceRecoveryTime
// 0x700250 ActorProcess::Function700250
// 0x700270 ActorProcess::Function700270
// 0x700c60 ActorProcess::GetAttackData
// 0x700d20 ActorProcess::ClearAttackData
// 0x700d60 ActorProcess::Function700d60
// 0x700d80 ActorProcess::Function700d80
// 0x700dc0 ActorProcess::Function700dc0
// 0x700de0 ActorProcess::HasNoQueuedGreetings
// 0x700e70 ActorProcess::GetPlayerActionReaction
// 0x700e90 ActorProcess::SetPlayerActionReaction
// 0x701210 ActorProcess::SetLastBumpDirection
// 0x701230 ActorProcess::GetLastBumpDirection
// 0x701250 ActorProcess::Function701250
// 0x7012f0 ActorProcess::GetMovementSpeeds
// 0x701320 ActorProcess::SetCrimeToReactTo
// 0x701340 ActorProcess::GetCrimeToReactTo
// 0x701360 ActorProcess::Function701360
// 0x7013a0 ActorProcess::Function7013a0
// 0x7013c0 ActorProcess::Function7013c0
// 0x7013e0 ActorProcess::Function7013e0
// 0x701400 ActorProcess::Function701400
// 0x701420 ActorProcess::GetAbsorbTimer
// 0x701440 ActorProcess::SetAbsorbTimer
// 0x701460 ActorProcess::Function701460
// 0x7015b0 ActorProcess::ClearReanimation
// 0x701660 ActorProcess::GetReanimateSpell
// 0x701e20 ActorProcess::SetFarGeometry
// 0x701e40 ActorProcess::HasFarGeometry
// 0x7022c0 ActorProcess::Function7022c0
// 0x702370 ActorProcess::GetCachedActorHeight
// 0x702560 ActorProcess::Function702560
// 0x704c50 ActorProcess::GetKnowledgeArray
#include "ActorProcess_700020.h"
#include <intrin.h>

// NiRefObject, NiRefObject::DeleteThis, BGSAttackData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// refCount: STANDIN GUESS(low)
class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    volatile long refCount;
};

class BGSAttackData : public NiRefObject {};


// defaultAttackData, emptyActorHandle, defaultActorHeight, ReleasePrevious: STANDIN GUESS(low)
extern const AttackDataPointer defaultAttackData;
extern const ActorHandle emptyActorHandle;
extern const float defaultActorHeight;
void ReleasePrevious(void* previous);

VOICE_STATE ActorProcess::GetVoiceState() const
{
    return high ? high->voiceState : static_cast<VOICE_STATE>(0);
}

void ActorProcess::SetVoiceState(VOICE_STATE value)
{
    if (high) {
        high->voiceState = value;
    }
}

TESShout* ActorProcess::GetCurrentShout() const
{
    return high ? high->currentShout : nullptr;
}

TESShoutVariation ActorProcess::GetCurrentShoutVariation() const
{
    return high ? high->currentShoutVariation : TESShoutVariation::kNone;
}

void ActorProcess::SetCurrentShoutVariation(TESShoutVariation value)
{
    if (high) {
        high->currentShoutVariation = value;
    }
}

float ActorProcess::GetVoiceTimeElapsed() const
{
    return high ? high->voiceTimeElapsed : 0.0f;
}

void ActorProcess::SetVoiceTimeElapsed(float value)
{
    if (high) {
        high->voiceTimeElapsed = value;
    }
}

void ActorProcess::SetVoiceRecoveryTime(float value)
{
    if (high) {
        high->voiceRecoveryTime = value;
    }
}

void ActorProcess::Function700250(bool value)
{
    if (high) {
        high->unk467 = value;
    }
}

bool ActorProcess::Function700270() const
{
    return high && high->unk467;
}

const AttackDataPointer& ActorProcess::GetAttackData() const
{
    if (high) {
        return high->attackData;
    }
    return defaultAttackData;
}

void ActorProcess::ClearAttackData()
{
    if (high) {
        if (auto* previous = high->attackData.pointer) {
            high->attackData.pointer = nullptr;
            // Release the process's reference. Only the final owner destroys the object.
            if (_InterlockedExchangeAdd(&previous->refCount, -1) == 1) {
                previous->DeleteThis();
            }
        }
    }
}

bool ActorProcess::Function700d60() const
{
    return high && high->flag45E;
}

void ActorProcess::Function700d80(bool value)
{
    if (high) {
        high->flag45E = value;
    }
}

void ActorProcess::Function700dc0(bool value)
{
    if (high) {
        high->unk469 = value;
    }
}

bool ActorProcess::HasNoQueuedGreetings() const
{
    return !high || high->greetingCount == 0;
}

PLAYER_ACTION ActorProcess::GetPlayerActionReaction() const
{
    return high ? high->playerActionReaction : static_cast<PLAYER_ACTION>(0);
}

void ActorProcess::SetPlayerActionReaction(PLAYER_ACTION value)
{
    if (high) {
        high->playerActionReaction = value;
    }
}

void ActorProcess::SetLastBumpDirection(float value)
{
    if (high) {
        high->lastBumpDirection = value;
    }
}

float ActorProcess::GetLastBumpDirection() const
{
    return high ? high->lastBumpDirection : 0.0f;
}

bool ActorProcess::Function701250(Movement::TypeData& output) const
{
    const bool available = high != nullptr;
    if (high) {
        output.AssignFrom(high->currentMovementType);
    }
    return available;
}

bool ActorProcess::GetMovementSpeeds(MovementSpeeds& output) const
{
    const bool available = high != nullptr;
    if (high) {
        output = high->currentMovementType.speeds;
    }
    return available;
}

void ActorProcess::SetCrimeToReactTo(Crime* value)
{
    if (high) {
        high->crimeToReactTo = value;
    }
}

Crime* ActorProcess::GetCrimeToReactTo() const
{
    return high ? high->crimeToReactTo : nullptr;
}

bool ActorProcess::Function701360() const
{
    return high && high->unk46D;
}

bool ActorProcess::Function7013a0() const
{
    return high && high->unk46E;
}

void ActorProcess::Function7013c0(bool value)
{
    if (high) {
        high->unk46E = value;
    }
}

bool ActorProcess::Function7013e0() const
{
    return high && high->unk46F;
}

void ActorProcess::Function701400(bool value)
{
    if (high) {
        high->unk46F = value;
    }
}

float ActorProcess::GetAbsorbTimer() const
{
    return high ? high->absorbTimer : 0.0f;
}

void ActorProcess::SetAbsorbTimer(float value)
{
    if (high) {
        high->absorbTimer = value > 0.0f ? value : 0.0f;
    }
}

void ActorProcess::Function701460(void*& source)
{
    if (auto* data = high) {
        auto* replacement = source;
        auto* previous = data->unk370;
        if (replacement != previous) {
            source = nullptr;
            data->unk370 = replacement;
            ReleasePrevious(previous);
        }
    }
}

void ActorProcess::ClearReanimation()
{
    if (auto* data = high) {
        data->reanimateCaster = emptyActorHandle;
        data->reanimateSpell = nullptr;
    }
}

MagicItem* ActorProcess::GetReanimateSpell() const
{
    return high ? high->reanimateSpell : nullptr;
}

void ActorProcess::SetFarGeometry(bool value)
{
    if (high) {
        high->farGeometry = value;
    }
}

bool ActorProcess::HasFarGeometry() const
{
    return high && high->farGeometry;
}

bool ActorProcess::Function7022c0() const
{
    return high && high->unk1E8;
}

float ActorProcess::GetCachedActorHeight() const
{
    return high ? high->cachedActorHeight : defaultActorHeight;
}

void ActorProcess::Function702560(const Movement::TypeData& input)
{
    if (high) {
        high->currentMovementType.AssignFrom(input);
    }
}

KnowledgeArray& ActorProcess::GetKnowledgeArray()
{
    return high->knowledgeArray;
}
