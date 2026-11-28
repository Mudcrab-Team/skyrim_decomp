// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActorValueMeter, ActorValueMeter::GetFillPercent, actorValue, PlayerCharacter: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner, GetActorValue, GetActorValueModifier, gPlayerCharacter: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float GetActorValue(std::int32_t a_av);
};

class PlayerCharacter
{
public:
    float GetActorValueModifier(std::int32_t a_modifier, std::int32_t a_av);

    std::uint8_t unk00[0xB8];
    ActorValueOwner avOwner;
};

extern PlayerCharacter* gPlayerCharacter;

class ActorValueMeter
{
public:
    float GetFillPercent();

    std::uint8_t unk00[0x48];
    std::int32_t actorValue;
};

static_assert(offsetof(PlayerCharacter, avOwner) == 0xB8, "avOwner offset");
static_assert(offsetof(ActorValueMeter, actorValue) == 0x48, "actorValue offset");
