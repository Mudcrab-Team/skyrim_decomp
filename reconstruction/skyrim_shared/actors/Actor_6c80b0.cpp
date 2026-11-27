// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6c80b0 Actor::GetAttackReach
// Adapted bodies: none
#include "Actor_6c80b0.h"

// Compute the actor's scaled melee attack reach from bash, equipped weapon, or unarmed reach.
float Actor::GetAttackReach() const
{
    TESObjectWEAP* weapon = GetEquippedWeapon();
    float reach;
    if (actorState1.meleeAttackState == ATTACK_STATE_ENUM::kBash) {
        reach = fCombatBashReach;
    } else if (weapon) {
        reach = ComputeWeaponReach(weapon->reach);
    } else {
        reach = GetUnarmedReach();
    }
    reach *= GetScale();
    if (this == g_playerCharacter && g_playerCamera->cameraState == 4) {
        reach *= fPlayerReachMult;
    }
    return reach;
}
