// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6c6380 Character::GetActorValueRegenRate
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "Character_6c6380.h"

float Character::GetActorValueRegenRate(ActorValue a_akValue)
{
    float rate = regenRateDefault;
    switch (a_akValue) {
    case ActorValue::kHealth:
        rate = avOwner.GetActorValue(ActorValue::kCombatHealthRegenMultiply) == 0.0f ? regenRateHealth : 0.0f;
        break;
    case ActorValue::kMagicka:
        rate = regenRateMagicka;
        break;
    case ActorValue::kStamina:
        rate = regenRateStamina;
        break;
    default:
        break;
    }
    return rate;
}
