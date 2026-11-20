// Source exposure: mixed (pinned image listings, project ActorProcess units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations from the pinned listings using the cited declarations.
// Adapted bodies: none
// 0x6e9330 ActorProcess::IsIgnoringCombat
// 0x6e9670 ActorProcess::AdvanceEssentialDownTimer
// 0x6e9690 ActorProcess::GetEssentialDownTimer
// 0x6e96a0 ActorProcess::SetEssentialDownTimer
// 0x6e96b0 ActorProcess::SetCurrentActionComplete
// 0x6e96e0 ActorProcess::IsCurrentActionComplete
// 0x6e9700 ActorProcess::GetTarget
// 0x6e9720 ActorProcess::GetFollowTarget
// 0x6e9740 ActorProcess::IsEscortingPlayer
// 0x6e9750 ActorProcess::SetTarget
// 0x6e9790 ActorProcess::SetFollowTarget
// 0x6e97a0 ActorProcess::SetEscortingPlayer
// 0x6e97e0 ActorProcess::SetNumberItemsActivate
// 0x6e9840 ActorProcess::Function6e9840
// 0x6e9860 ActorProcess::Function6e9860
// 0x6e9890 ActorProcess::Function6e9890
// 0x6e98c0 ActorProcess::IsProcessTimerExpired
// 0x6e9a00 ActorProcess::GetCurrentProcedureIndex
// 0x6e9a10 ActorProcess::AdvanceProcedureIndex
// 0x6ea000 ActorProcess::IsAlert
// 0x6ea020 ActorProcess::SetAlert
// 0x6ea1a0 ActorProcess::IsFollower
// 0x6ea1c0 ActorProcess::SetFollower
// 0x6ea7e0 ActorProcess::Function6ea7e0
// 0x6ea7f0 ActorProcess::Function6ea7f0
// 0x6ea910 ActorProcess::IsTargetActivated
// 0x6ea920 ActorProcess::SetTargetActivated
// 0x6ea950 ActorProcess::Function6ea950
// 0x6ea9c0 ActorProcess::Function6ea9c0
// 0x6eaab0 ActorProcess::IsPackageDoneOnce
// 0x6eaad0 ActorProcess::SetPackageDoneOnce
// 0x6eab00 ActorProcess::GetDeathTime
// 0x6eab10 ActorProcess::SetDeathTime
// 0x6eaf00 ActorProcess::AddTrackedDamage
// 0x6eb4b0 ActorProcess::GetEquippedRightHand
#include "ActorProcess_6e9330.h"

// elapsedFrameTime, processTime, trackedDamageSource: STANDIN GUESS(low)
extern const float elapsedFrameTime;
extern const float processTime;
extern const void* trackedDamageSource;

bool ActorProcess::IsIgnoringCombat() const
{
    return ignoringCombat;
}

void ActorProcess::AdvanceEssentialDownTimer()
{
    essentialDownTimer -= elapsedFrameTime;
}

float ActorProcess::GetEssentialDownTimer() const
{
    return essentialDownTimer;
}

void ActorProcess::SetEssentialDownTimer(float value)
{
    essentialDownTimer = value;
}

void ActorProcess::SetCurrentActionComplete(bool value)
{
    if (value) {
            lowProcessFlags |= 2;
        } else {
            lowProcessFlags &= ~2;
        }
}

bool ActorProcess::IsCurrentActionComplete() const
{
    return (lowProcessFlags >> 1) & 1;
}

RefHandle ActorProcess::GetTarget() const
{
    return target;
}

RefHandle ActorProcess::GetFollowTarget() const
{
    return followTarget;
}

bool ActorProcess::IsEscortingPlayer() const
{
    return escortingPlayer;
}

void ActorProcess::SetTarget(Actor* actor, const RefHandle& value)
{
    if (middleHigh) {
        const RefHandle handle(value);
        Function720440(actor, handle);
    } else {
        target = value;
    }
}

void ActorProcess::SetFollowTarget(const RefHandle& value)
{
    followTarget = value;
}

void ActorProcess::SetEscortingPlayer(bool value)
{
    escortingPlayer = value;
}

void ActorProcess::SetNumberItemsActivate(std::int32_t value)
{
    numberItemsActivate = value;
}

bool ActorProcess::Function6e9840() const
{
    return (lowProcessFlags >> 2) & 1;
}

void ActorProcess::Function6e9860(bool value)
{
    if (value) {
            lowProcessFlags |= 4;
        } else {
            lowProcessFlags &= ~4;
        }
}

void ActorProcess::Function6e9890(std::uint64_t value)
{
    unk100 = value;
}

bool ActorProcess::IsProcessTimerExpired() const
{
    return processTime - timerStart > timerDuration;
}

std::int32_t ActorProcess::GetCurrentProcedureIndex() const
{
    return currentPackage.currentProcedureIndex;
}

void ActorProcess::AdvanceProcedureIndex(std::uint32_t delta)
{
    currentPackage.currentProcedureIndex += delta;
}

bool ActorProcess::IsAlert() const
{
    return (lowProcessFlags >> 3) & 1;
}

void ActorProcess::SetAlert(bool value)
{
    if (value) {
            lowProcessFlags |= 8;
        } else {
            lowProcessFlags &= ~8;
        }
}

bool ActorProcess::IsFollower() const
{
    return (lowProcessFlags >> 4) & 1;
}

void ActorProcess::SetFollower(bool value)
{
    if (value) {
            lowProcessFlags |= 16;
        } else {
            lowProcessFlags &= ~16;
        }
}

void ActorProcess::Function6ea7e0(std::uint64_t value)
{
    unk128 = value;
}

std::uint64_t ActorProcess::Function6ea7f0() const
{
    return unk128;
}

bool ActorProcess::IsTargetActivated() const
{
    return (lowProcessFlags >> 0) & 1;
}

void ActorProcess::SetTargetActivated(bool value)
{
    if (value) {
            lowProcessFlags |= 1;
        } else {
            lowProcessFlags &= ~1;
        }
}

RefHandle ActorProcess::Function6ea950() const
{
    return reference118;
}

RefHandle ActorProcess::Function6ea9c0() const
{
    return reference11C;
}

bool ActorProcess::IsPackageDoneOnce() const
{
    return (lowProcessFlags >> 5) & 1;
}

void ActorProcess::SetPackageDoneOnce(bool value)
{
    if (value) {
            lowProcessFlags |= 32;
        } else {
            lowProcessFlags &= ~32;
        }
}

float ActorProcess::GetDeathTime() const
{
    return deathTime;
}

void ActorProcess::SetDeathTime(float value)
{
    deathTime = value;
}

void ActorProcess::AddTrackedDamage(const void* source, float damage)
{
    if (source && source == trackedDamageSource) {
        trackedDamage += damage;
    }
}

TESForm* ActorProcess::GetEquippedRightHand() const
{
    return equippedObjects[1];
}
