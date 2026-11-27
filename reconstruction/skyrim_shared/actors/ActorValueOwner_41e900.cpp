// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x41e900 ActorValueOwner::GetArmorRatingSkillMultiplier
// Adapted bodies: none
#include "ActorValueOwner_41e900.h"

// Compute the skill-based multiplier using player or NPC game settings.
float ActorValueOwner::GetArmorRatingSkillMultiplier(const ActorValueOwner* a_owner, float a_skill)
{
    if (a_owner && a_owner->GetIsPlayerOwner()) {
        return (fPlayerMaxMult41e900 - fPlayerMinMult41e900) * (a_skill * 0.01f) + fPlayerMinMult41e900;
    }
    return (fNpcMaxMult41e900 - fNpcMinMult41e900) * (a_skill * 0.01f) + fNpcMinMult41e900;
}
