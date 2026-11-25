// Source exposure: mixed (pinned image listings, project ActorProcess units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial process and package layouts adapted from the cited community declarations. Stamped as a twin of matched 0x6eab00 (skyrim/ai/ActorProcess_6e9330): source copied, names replaced by placeholders.
// Actor, ActorPackage, TESForm, MiddleHighProcessData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::middleHigh, AIProcess::currentPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RefHandle, timerStart, timerDuration, reference118, reference11C: STANDIN GUESS(low)
// Function720440: STANDIN GUESS(low)
// Function142ce0, Owner142ce0: GUESS(low) STANDIN
// GetEquippedRightHand, IsIgnoringCombat, GetEssentialDownTimer, IsEscortingPlayer, GetCurrentProcedureIndex, Function6ea7f0, SetEssentialDownTimer, SetEscortingPlayer, SetNumberItemsActivate, Function6e9890, Function6ea7e0, SetDeathTime, AdvanceEssentialDownTimer, AdvanceProcedureIndex, IsTargetActivated, SetTargetActivated, IsCurrentActionComplete, SetCurrentActionComplete, Function6e9840, Function6e9860, IsAlert, SetAlert, IsFollower, SetFollower, IsPackageDoneOnce, SetPackageDoneOnce, GetTarget, GetFollowTarget, Function6ea950, Function6ea9c0, SetFollowTarget, SetTarget, IsProcessTimerExpired, AddTrackedDamage: GUESS(low) STANDIN
#pragma once
#include "ActorProcess_6e9330.h"

class Owner142ce0
{
public:
    bool IsIgnoringCombat() const;
    void AdvanceEssentialDownTimer();
    float GetEssentialDownTimer() const;
    void SetEssentialDownTimer(float value);
    void SetCurrentActionComplete(bool value);
    bool IsCurrentActionComplete() const;
    RefHandle GetTarget() const;
    RefHandle GetFollowTarget() const;
    bool IsEscortingPlayer() const;
    void SetTarget(Actor* actor, const RefHandle& value);
    void SetFollowTarget(const RefHandle& value);
    void SetEscortingPlayer(bool value);
    void SetNumberItemsActivate(std::int32_t value);
    bool Function6e9840() const;
    void Function6e9860(bool value);
    void Function6e9890(std::uint64_t value);
    bool IsProcessTimerExpired() const;
    std::int32_t GetCurrentProcedureIndex() const;
    void AdvanceProcedureIndex(std::uint32_t delta);
    bool IsAlert() const;
    void SetAlert(bool value);
    bool IsFollower() const;
    void SetFollower(bool value);
    void Function6ea7e0(std::uint64_t value);
    std::uint64_t Function6ea7f0() const;
    bool IsTargetActivated() const;
    void SetTargetActivated(bool value);
    RefHandle Function6ea950() const;
    RefHandle Function6ea9c0() const;
    bool IsPackageDoneOnce() const;
    void SetPackageDoneOnce(bool value);
    float Function142ce0() const;
    void SetDeathTime(float value);
    void AddTrackedDamage(const void* source, float damage);
    TESForm* GetEquippedRightHand() const;

private:
    void Function720440(Actor* actor, const RefHandle& handle);

// AIProcess::numberItemsActivate, AIProcess::essentialDownTimer, AIProcess::deathTime, AIProcess::trackedDamage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::equippedObjects, AIProcess::unk100, AIProcess::followTarget, AIProcess::target, AIProcess::unk128: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::lowProcessFlags, AIProcess::ignoringCombat, AIProcess::escortingPlayer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding00[8];
    MiddleHighProcessData* middleHigh;
    std::uint8_t padding10[8];
    ActorPackage currentPackage;
    std::uint8_t padding48[0x10];
    std::int32_t numberItemsActivate;
    std::uint8_t padding5C[0x34];
    float essentialDownTimer;
    float deathTime;
    float trackedDamage;
    std::uint8_t padding9C[0x54];
    TESForm* equippedObjects[2];
    std::uint64_t unk100;
    float timerStart;
    float timerDuration;
    RefHandle followTarget;
    RefHandle target;
    RefHandle reference118;
    RefHandle reference11C;
    std::uint8_t padding120[8];
    std::uint64_t unk128;
    std::uint8_t padding130[6];
    std::uint8_t lowProcessFlags;
    std::uint8_t padding137[2];
    bool ignoringCombat;
    std::uint8_t padding13A;
    bool escortingPlayer;
};

