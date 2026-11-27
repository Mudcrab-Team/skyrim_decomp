// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorValueOwner, GetWeaponStagger, Actor, TESObjectWEAP, BGSAttackData: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorBase41f5e0, AttackDataPtr41f5e0, g_playerCharacter41f5e0, g_staggerPlayerMassMult41f5e0, g_staggerMassMult41f5e0, g_staggerMassBase41f5e0, g_staggerEpsilon41f5e0, g_staggerMassOffset41f5e0, g_staggerMassScale41f5e0, ptr, staggerOffset, stagger, animType, unk00, unk08, unk18C, GetActorValue, GetAttackData: GUESS(low)
// 0x41f5e0 ActorValueOwner::GetWeaponStagger
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#pragma once

#include <cmath>
#include <cstddef>
#include <cstdint>

struct BGSAttackData
{
    std::uint8_t unk00[0x34];
    float staggerOffset;
};

struct AttackDataPtr41f5e0
{
    BGSAttackData* ptr;
};

struct TESObjectWEAP
{
    std::uint8_t unk00[0x188];
    float stagger;
    std::uint8_t unk18C[0x11];
    std::uint8_t animType;
};

class ActorBase41f5e0
{
public:
    virtual ~ActorBase41f5e0();
    std::uint8_t unk08[0xB0];
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(std::uint32_t a_av);

    static float GetWeaponStagger(
        ActorValueOwner* a_attacker,
        ActorValueOwner* a_target,
        TESObjectWEAP* a_weapon,
        float a_staggerOverride);
};

class Actor : public ActorBase41f5e0, public ActorValueOwner
{
public:
    AttackDataPtr41f5e0* GetAttackData();
};

extern Actor* g_playerCharacter41f5e0;
extern const float g_staggerPlayerMassMult41f5e0;
extern const float g_staggerMassMult41f5e0;
extern const float g_staggerMassBase41f5e0;
extern const float g_staggerEpsilon41f5e0;
extern const float g_staggerMassOffset41f5e0;
extern const float g_staggerMassScale41f5e0;

static_assert(sizeof(ActorBase41f5e0) == 0xB8, "ActorBase41f5e0 size");
static_assert(offsetof(BGSAttackData, staggerOffset) == 0x34, "staggerOffset offset");
static_assert(offsetof(TESObjectWEAP, stagger) == 0x188, "stagger offset");
static_assert(offsetof(TESObjectWEAP, animType) == 0x19D, "animType offset");
