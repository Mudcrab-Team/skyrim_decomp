// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP, InventoryEntryData, ActorProcess, PlayerCamera, Actor, Actor::currentProcess, Actor::GetAttackReach: CRASHLOGGER_PDB(59818@2026.10.24)
// ATTACK_STATE_ENUM, ATTACK_STATE_ENUM::kBash, ActorState1, Actor::actorState1, TESObjectREFR::GetScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ComputeWeaponReach, g_playerCharacter, g_playerCamera, fCombatBashReach, fPlayerReachMult, ActorProcess::GetEquippedEntryData, Actor::GetUnarmedReach, TESObjectWEAP::reach, PlayerCamera::cameraState: GUESS(low)
// TESObjectWEAP::unk00, PlayerCamera::unk00, Actor::unk00, Actor::unkCC, ActorState1::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESObjectWEAP
{
public:
    std::uint8_t unk00[0x174];
    float        reach;  // 0x174
};
static_assert(offsetof(TESObjectWEAP, reach) == 0x174, "TESObjectWEAP::reach offset");

class InventoryEntryData
{
public:
    TESObjectWEAP* object;  // 0x00
};

class ActorProcess
{
public:
    InventoryEntryData* GetEquippedEntryData(bool a_leftHand) const;
};

class PlayerCamera
{
public:
    std::uint8_t  unk00[0x20];
    std::uint32_t cameraState;  // 0x20
};
static_assert(offsetof(PlayerCamera, cameraState) == 0x20, "PlayerCamera::cameraState offset");

enum class ATTACK_STATE_ENUM : std::uint32_t
{
    kBash = 6,
};

struct ActorState1
{
    std::uint32_t     unk00 : 28;
    ATTACK_STATE_ENUM meleeAttackState : 4;
};

class Actor;

float ComputeWeaponReach(float a_reach);

extern Actor*        g_playerCharacter;
extern PlayerCamera* g_playerCamera;
extern float         fCombatBashReach;
extern float         fPlayerReachMult;

class Actor
{
public:
    float GetScale() const;
    float GetUnarmedReach() const;
    float GetAttackReach() const;

    TESObjectWEAP* GetEquippedWeapon() const
    {
        if (currentProcess) {
            if (InventoryEntryData* entry = currentProcess->GetEquippedEntryData(false)) {
                return entry->object;
            }
        }
        return nullptr;
    }

    std::uint8_t  unk00[0xc8];
    ActorState1   actorState1;     // 0xc8
    std::uint8_t  unkCC[0x2c];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, actorState1) == 0xc8, "Actor::actorState1 offset");
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
