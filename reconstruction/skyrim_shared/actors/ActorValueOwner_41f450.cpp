// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x41f450 ActorValueOwner::GetArmorRatingSkillMultiplier
// Adapted bodies: none
#include "ActorValueOwner_41f450.h"

// Compute the skill-based multiplier using player or NPC game settings.
float ActorValueOwner::GetArmorRatingSkillMultiplier(const ActorValueOwner* a_owner, float a_skill)
{
    if (a_owner && a_owner->GetIsPlayerOwner()) {
        return (fPlayerMaxMult41f450 - fPlayerMinMult41f450) * (a_skill * 0.01f) + fPlayerMinMult41f450;
    }
    return (fNpcMaxMult41f450 - fNpcMinMult41f450) * (a_skill * 0.01f) + fNpcMinMult41f450;
}
