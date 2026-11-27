// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x41f5e0 ActorValueOwner::GetWeaponStagger
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "ActorValueOwner_41f5e0.h"

// Compute weapon stagger magnitude from attacker, target mass, weapon stagger, and bow bonus.
float ActorValueOwner::GetWeaponStagger(
    ActorValueOwner* a_attacker,
    ActorValueOwner* a_target,
    TESObjectWEAP* a_weapon,
    float a_staggerOverride)
{
    float targetMass = a_target ? a_target->GetActorValue(0x24) : 0.0f;
    float scale = 1.0f;

    if (a_staggerOverride == 0.0f && (a_weapon || a_attacker)) {
        Actor* attackerActor = static_cast<Actor*>(a_attacker);
        float attackMult = 1.0f;
        if (attackerActor) {
            BGSAttackData* data = attackerActor->GetAttackData()->ptr;
            attackMult = data ? data->staggerOffset : 0.0f;
        }
        float weapStagger = a_weapon ? a_weapon->stagger : 1.0f;
        a_staggerOverride = weapStagger * attackMult;
    }

    Actor* targetActor = static_cast<Actor*>(a_target);
    if (targetActor && targetActor == g_playerCharacter41f5e0) {
        targetMass *= g_staggerPlayerMassMult41f5e0;
    }

    float denom = g_staggerMassMult41f5e0 * targetMass + g_staggerMassBase41f5e0;
    if (std::fabs(denom) > g_staggerEpsilon41f5e0) {
        scale = 1.0f / denom;
    }

    float result = scale * a_staggerOverride;
    float penalty = (targetMass - g_staggerMassOffset41f5e0) * g_staggerMassScale41f5e0;
    if (penalty < 0.0f) {
        penalty = 0.0f;
    }

    if (a_weapon && a_attacker && (a_weapon->animType == 7 || a_weapon->animType == 9)) {
        result += a_attacker->GetActorValue(0x57);
    }

    return result - penalty;
}
