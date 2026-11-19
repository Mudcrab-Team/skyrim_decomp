// Source exposure: mixed (pinned image listings, project ActorProcess units and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial process declarations adapted from CommonLibSSE-NG AIProcess and HighProcessData.
// IsInCommandState, Function6f5140, Function6f5160, IsTalkingToPlayer, SetTalkingToPlayer: GUESS(low)
// Function6f51c0, Function6f51e0, SetBreathTimer, IsGreetingPlayer, SetGreetingPlayer: GUESS(low)
// SetSoundDelay, SetIdleTimer, Function6f5e20, Function6f5e80, Function6f5ea0: GUESS(low)
// Function6f60c0, SetPlantedExplosiveFlag, HasPlantedExplosiveFlag, HasStartedAggroRadius, SetAggroRadiusStarted: GUESS(low)
// SetDualCasting, Function6f6470, Function6f6670, Function6f6dc0, Function6f6f80: GUESS(low)
// GetGreetingTimer, SetGreetingTimer, GetLastGreeting, SetLastGreeting, GetExclusiveTimer: GUESS(low)
// SetExclusiveTimer, SetBumpState, GetBumpState, Function6fde50, GetFadeState: GUESS(low)
// SetDefaultHeadtrackTarget, Function6fe6b0, SetScriptHeadtrackTarget, SetCombatHeadtrackTarget, SetDialogueHeadtrackTarget: GUESS(low)
// SetProcedureHeadtrackTarget, GetLightLevel, SetLightLevel, SetPathLookAtTarget: GUESS(low)
// IsArrested, ClearActionHeadtrackTarget, HighProcessData, AIProcess::high, ObjectRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopicInfo, TESObjectREFR, FADE_STATE, BUMP_TYPE, HEAD_TRACK_TYPE: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kNone, kNormal, SetHeadtrackTarget, ClearHeadtrackTarget, kDefault: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// kAction, kScript, kCombat, kDialogue, kProcedure: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fadeState, pathLookAtTarget, bumpedState, unk2A4, soundDelay: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// greetingTimer, exclusiveTimer, idleTimer, breathTimer, lastGreeting: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk358, unk368, lightLevel, greetingPlayer, talkingToPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// inCommandState, unk45C, isDualCasting, getPlantedExplosive, arrested: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// aggroRadiusStarted: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// timeStampValue, value2AC, actionIndex, field3B8, value3EC: STANDIN GUESS(low)
// counter448, AddressedField, Function71f9c0, padding: STANDIN GUESS(low)
// ActorProcess: EXE_RTTI
#pragma once

#include <cstdint>

class TESObjectREFR;
class TESTopicInfo;
struct AddressedField {};
struct ObjectRefHandle { std::uint32_t value; };

struct HighProcessData
{
    enum class FADE_STATE : std::uint32_t { kNormal = 0 };
    enum class BUMP_TYPE : std::int32_t { kNone = -1 };
    enum HEAD_TRACK_TYPE : std::uint32_t { kDefault, kAction, kScript, kCombat, kDialogue, kProcedure };

    std::uint8_t padding000[0x130];
    FADE_STATE fadeState;
    std::uint8_t padding134[0x48];
    ObjectRefHandle pathLookAtTarget;
    std::uint8_t padding180[0x78];
    float timeStampValue;
    BUMP_TYPE bumpedState;
    std::uint8_t padding200[0xA4];
    float unk2A4;
    std::uint8_t padding2A8[0x4];
    float value2AC;
    std::uint8_t padding2B0[0x28];
    std::int16_t actionIndex;
    std::uint8_t padding2DA[0x1E];
    float soundDelay;
    std::uint8_t padding2FC[0x18];
    float greetingTimer;
    float exclusiveTimer;
    float idleTimer;
    std::uint8_t padding320[0x4];
    float breathTimer;
    std::uint8_t padding328[0x8];
    TESTopicInfo* lastGreeting;
    std::uint8_t padding338[0x20];
    std::uint64_t unk358;
    std::uint8_t padding360[0x8];
    std::uint32_t unk368;
    std::uint8_t padding36C[0x3C];
    float lightLevel;
    std::uint8_t padding3AC[0xC];
    AddressedField field3B8;
    std::uint8_t padding3B9[0x33];
    float value3EC;
    std::uint8_t padding3F0[0x58];
    std::uint16_t counter448;
    std::uint8_t padding44A[0xA];
    bool greetingPlayer;
    std::uint8_t padding455[0x3];
    bool talkingToPC;
    bool inCommandState;
    std::uint8_t padding45A[0x2];
    std::uint8_t unk45C;
    std::uint8_t padding45D[0x2];
    bool isDualCasting;
    bool getPlantedExplosive;
    std::uint8_t padding461[0x1];
    bool arrested;
    std::uint8_t padding463[0xF];
    bool aggroRadiusStarted;

    void SetHeadtrackTarget(HEAD_TRACK_TYPE type, TESObjectREFR* target);
    void Function71f9c0(HEAD_TRACK_TYPE type, void* target);
    void ClearHeadtrackTarget(HEAD_TRACK_TYPE type, bool defaultHold);
};

class ActorProcess
{
public:
    bool IsInCommandState() const;
    std::uint64_t Function6f5140() const;
    void Function6f5160(std::uint64_t value);
    bool IsTalkingToPlayer() const;
    void SetTalkingToPlayer(bool value);
    std::uint32_t Function6f51c0() const;
    void Function6f51e0(std::uint32_t value);
    void SetBreathTimer(float value);
    bool IsGreetingPlayer() const;
    void SetGreetingPlayer(bool value);
    void SetSoundDelay(float value);
    void SetIdleTimer(float value);
    void Function6f5e20(float value);
    float Function6f5e80() const;
    void Function6f5ea0(float value);
    const AddressedField* Function6f60c0() const;
    void SetPlantedExplosiveFlag(bool value);
    bool HasPlantedExplosiveFlag() const;
    bool HasStartedAggroRadius() const;
    void SetAggroRadiusStarted(bool value);
    void SetDualCasting(bool value);
    std::int32_t Function6f6470() const;
    void Function6f6670(std::uint16_t value);
    void Function6f6dc0();
    void Function6f6f80();
    float GetGreetingTimer() const;
    void SetGreetingTimer(float value);
    TESTopicInfo* GetLastGreeting() const;
    void SetLastGreeting(TESTopicInfo* value);
    float GetExclusiveTimer() const;
    void SetExclusiveTimer(float value);
    bool IsArrested() const;
    void SetBumpState(HighProcessData::BUMP_TYPE value);
    HighProcessData::BUMP_TYPE GetBumpState() const;
    void Function6fde50();
    HighProcessData::FADE_STATE GetFadeState() const;
    void SetDefaultHeadtrackTarget(TESObjectREFR* target);
    void Function6fe6b0(void* target);
    void SetScriptHeadtrackTarget(TESObjectREFR* target);
    void SetCombatHeadtrackTarget(TESObjectREFR* target);
    void SetDialogueHeadtrackTarget(TESObjectREFR* target);
    void SetProcedureHeadtrackTarget(TESObjectREFR* target);
    void ClearActionHeadtrackTarget(bool defaultHold);
    float GetLightLevel() const;
    void SetLightLevel(float value);
    void SetPathLookAtTarget(const ObjectRefHandle& value);

private:
    std::uint8_t padding[0x10];
    HighProcessData* high;
};
