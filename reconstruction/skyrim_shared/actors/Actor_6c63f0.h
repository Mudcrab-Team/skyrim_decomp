// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written from the listing and CrashLogger PDB declarations; see Adapted bodies
// Adapted bodies: TestBit, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// Actor, CheckClampDamageModifier_1406222F0, ActorValueOwner, ActorValueInfo, ActorValueList: CRASHLOGGER_PDB(59818@2026.10.24)
// g_actorValueList6c63f0, g_essentialHealthFloor6c63f0, g_zeroClamp6c63f0, TestBit, actorValues, flags, avOwner, unk00, unk08, unk60, GetActorValue, GetBaseActorValue, GetActorValueModifier, IsEssential, VFunc: GUESS(low)
// 0x6c63f0 Actor::CheckClampDamageModifier_1406222F0
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once

#include <cstddef>
#include <cstdint>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

struct ActorValueInfo
{
    std::uint8_t unk00[0x60];
    std::uint32_t flags;
};

struct ActorValueList
{
    std::uint8_t unk00[0x8];
    ActorValueInfo* actorValues[164];
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(std::uint32_t a_av);
    virtual float GetBaseActorValue(std::uint32_t a_av);
};

class Actor
{
public:
    float GetActorValueModifier(std::uint32_t a_mod, std::uint32_t a_av);
    bool IsEssential(bool a_arg);
    float CheckClampDamageModifier_1406222F0(std::int32_t a_av, float a_delta);

    std::uint8_t unk00[0xB8];
    ActorValueOwner avOwner;
};

extern ActorValueList* g_actorValueList6c63f0;
extern const float g_essentialHealthFloor6c63f0;
extern const float g_zeroClamp6c63f0;

static_assert(offsetof(ActorValueList, actorValues) == 0x8, "actorValues offset");
static_assert(sizeof(ActorValueInfo) == 0x64, "ActorValueInfo size");
static_assert(offsetof(Actor, avOwner) == 0xB8, "avOwner offset");
