// Source exposure: mixed (pinned image listings, project ActorProcess units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial process and movement declarations adapted from CommonLibSSE-NG.
// ActorProcess: EXE_RTTI
// HighProcessData, AIProcess::high: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSAttackData, ActorHandle, VOICE_STATE, PLAYER_ACTION: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, Crime, TESShout, MagicItem, Movement::TypeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESShout::VariationID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetVoiceState, GetCurrentShout, GetCurrentShoutVariation, GetVoiceTimeElapsed, GetPlayerActionReaction: GUESS(low)
// GetLastBumpDirection, GetCrimeToReactTo, GetAbsorbTimer, GetReanimateSpell: GUESS(low)
// SetVoiceState, SetCurrentShoutVariation, SetVoiceTimeElapsed, Function700250: GUESS(low)
// Function700d80, Function700dc0, SetPlayerActionReaction, SetLastBumpDirection, SetCrimeToReactTo: GUESS(low)
// Function7013c0, Function701400, SetFarGeometry, Function700270, Function700d60: GUESS(low)
// Function701360, Function7013a0, Function7013e0, HasFarGeometry, Function7022c0: GUESS(low)
// HasNoQueuedGreetings, ClearAttackData, Function701250, GetMovementSpeeds: GUESS(low)
// SetAbsorbTimer, Function701460, ClearReanimation, Function702560: GUESS(low)
// greetingCount, flag45E, AttackDataPointer, KnowledgeArray, MovementSpeeds: STANDIN GUESS(low)
// AssignFrom, TESShoutVariation, padding: STANDIN GUESS(low)
// GetCachedActorHeight, SetVoiceRecoveryTime, GetAttackData, GetKnowledgeArray: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class BGSAttackData;
class Crime;
class MagicItem;
class NiRefObject;
class TESShout;

enum class VOICE_STATE : std::uint32_t;
enum class PLAYER_ACTION : std::uint32_t;
enum class TESShoutVariation : std::uint32_t { kNone = static_cast<std::uint32_t>(-1) };

struct ActorHandle { std::uint32_t value; };
struct AttackDataPointer { BGSAttackData* pointer; };
struct KnowledgeArray { std::uint8_t storage[0x18]; };

// Movement::TypeData::directional, Movement::TypeData::movementSpeed, Movement::TypeData::rotationSpeed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct MovementSpeeds
{
    float directional;
    float movementSpeed;
    float rotationSpeed;
};

namespace Movement
{
    struct TypeData
    {
        std::uint8_t padding[0x34];
        MovementSpeeds speeds;

        void AssignFrom(const TypeData& source);
    };
}

struct HighProcessData
{
    // voiceState, currentShout, currentShoutVariation, voiceTimeElapsed, voiceRecoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // lastBumpDirection, reanimateCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // reanimateSpell, currentMovementType, cachedActorHeight, unk1E8, playerActionReaction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // knowledgeArray, attackData, unk370, absorbTimer, crimeToReactTo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // unk467, farGeometry, unk469, unk46D, unk46E: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // unk46F: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    VOICE_STATE voiceState;
    std::uint8_t padding004[0x4];
    TESShout* currentShout;
    TESShoutVariation currentShoutVariation;
    float voiceTimeElapsed;
    float voiceRecoveryTime;
    std::uint8_t padding01C[0xB8];
    float lastBumpDirection;
    std::uint8_t padding0D8[0x8];
    ActorHandle reanimateCaster;
    std::uint8_t padding0E4[0x4];
    MagicItem* reanimateSpell;
    Movement::TypeData currentMovementType;
    std::uint8_t padding130[0xB4];
    float cachedActorHeight;
    NiRefObject* unk1E8;
    std::uint8_t padding1F0[0x24];
    PLAYER_ACTION playerActionReaction;
    std::uint8_t padding218[0x8];
    KnowledgeArray knowledgeArray;
    std::uint8_t padding238[0x18];
    std::uint32_t greetingCount;
    std::uint8_t padding254[0x4];
    AttackDataPointer attackData;
    std::uint8_t padding260[0x110];
    void* unk370;
    std::uint8_t padding378[0xC0];
    float absorbTimer;
    std::uint8_t padding43C[0x4];
    Crime* crimeToReactTo;
    std::uint8_t padding448[0x16];
    bool flag45E;
    std::uint8_t padding45F[0x8];
    bool unk467;
    bool farGeometry;
    bool unk469;
    std::uint8_t padding46A[0x3];
    bool unk46D;
    bool unk46E;
    bool unk46F;
};

class ActorProcess
{
public:
    VOICE_STATE GetVoiceState() const;
    void SetVoiceState(VOICE_STATE value);
    TESShout* GetCurrentShout() const;
    TESShoutVariation GetCurrentShoutVariation() const;
    void SetCurrentShoutVariation(TESShoutVariation value);
    float GetVoiceTimeElapsed() const;
    void SetVoiceTimeElapsed(float value);
    void SetVoiceRecoveryTime(float value);
    void Function700250(bool value);
    bool Function700270() const;
    const AttackDataPointer& GetAttackData() const;
    void ClearAttackData();
    bool Function700d60() const;
    void Function700d80(bool value);
    void Function700dc0(bool value);
    bool HasNoQueuedGreetings() const;
    PLAYER_ACTION GetPlayerActionReaction() const;
    void SetPlayerActionReaction(PLAYER_ACTION value);
    void SetLastBumpDirection(float value);
    float GetLastBumpDirection() const;
    bool Function701250(Movement::TypeData& output) const;
    bool GetMovementSpeeds(MovementSpeeds& output) const;
    void SetCrimeToReactTo(Crime* value);
    Crime* GetCrimeToReactTo() const;
    bool Function701360() const;
    bool Function7013a0() const;
    void Function7013c0(bool value);
    bool Function7013e0() const;
    void Function701400(bool value);
    float GetAbsorbTimer() const;
    void SetAbsorbTimer(float value);
    void Function701460(void*& source);
    void ClearReanimation();
    MagicItem* GetReanimateSpell() const;
    void SetFarGeometry(bool value);
    bool HasFarGeometry() const;
    bool Function7022c0() const;
    float GetCachedActorHeight() const;
    void Function702560(const Movement::TypeData& input);
    KnowledgeArray& GetKnowledgeArray();

private:
    std::uint8_t padding[0x10];
    HighProcessData* high;
};
