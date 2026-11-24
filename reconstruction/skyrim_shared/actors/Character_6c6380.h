// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the actor-value owner base only
// Character::GetActorValueRegenRate: GUESS(low)
// Character::avOwner, Character::pad00: GUESS(low); NG's ActorValueOwner base, 8 bytes later in this build, modelled as a member
// ActorValueOwner, ActorValueOwner::GetActorValue, ActorValue, kHealth, kMagicka, kStamina, kCombatHealthRegenMultiply: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the slots and enumerators the body uses
// regenRateStamina, regenRateDefault, regenRateMagicka, regenRateHealth: GUESS(low); the four float constants the body returns
#pragma once

#include <cstdint>
#include <cstddef>

enum class ActorValue : std::uint32_t
{
    kHealth = 24,
    kMagicka = 25,
    kStamina = 26,
    kCombatHealthRegenMultiply = 134
};

extern float regenRateStamina;
extern float regenRateDefault;
extern float regenRateMagicka;
extern float regenRateHealth;

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();                           // 00
    virtual float GetActorValue(ActorValue a_akValue);    // 01
};

class Character
{
public:
    float GetActorValueRegenRate(ActorValue a_akValue);  // compared: 0x6c6380

    std::uint8_t    pad00[0xB8];
    ActorValueOwner avOwner;  // B8
};
