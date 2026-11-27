// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorValueOwner, ActorProcess, Character, Actor::currentProcess, Character::sub_140620550: CRASHLOGGER_PDB(59818@2026.10.24)
// CachedValuesData, ActorProcess::cachedValues, ActorValueOwner::GetActorValue, ActorValueOwner::GetPermanentActorValue: GUESS(low)
// CachedValuesData::unk00, CachedValuesData::flags, ActorProcess::unk00, Character::unk00, Character::unkC0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct CachedValuesData
{
    std::uint8_t  unk00[0x2c];
    std::uint32_t flags;  // 0x2c
};
static_assert(offsetof(CachedValuesData, flags) == 0x2c, "CachedValuesData::flags offset");

class ActorProcess
{
public:
    std::uint8_t      unk00[0x50];
    CachedValuesData* cachedValues;  // 0x50
};
static_assert(offsetof(ActorProcess, cachedValues) == 0x50, "ActorProcess::cachedValues offset");

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(std::int32_t a_av) const;           // 0x01 (0x08)
    virtual float GetPermanentActorValue(std::int32_t a_av) const;  // 0x02 (0x10)
};

class TESObjectREFRBase
{
public:
    virtual ~TESObjectREFRBase();

    std::uint8_t unk08[0xb0];
};
static_assert(sizeof(TESObjectREFRBase) == 0xb8, "TESObjectREFRBase size");

class Character : public TESObjectREFRBase, public ActorValueOwner
{
public:
    bool sub_140620550(std::int32_t a_av) const;

    std::uint8_t  unkC0[0x38];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Character, currentProcess) == 0xf8, "Character::currentProcess offset");
