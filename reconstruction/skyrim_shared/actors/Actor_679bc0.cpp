// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x679bc0 Actor::ResetHealthAndLimbs
// Adapted bodies: none
#include "Actor_679bc0.h"

// Restore any negative health damage modifier when the data handler is not loading.
void Actor::ResetHealthAndLimbs()
{
    if (!TESDataHandler::singleton->IsLoading()) {
        float damage = GetActorValueModifier(ACTOR_VALUE_MODIFIER::kDamage, ActorValue::kHealth);
        if (damage < 0.0f) {
            RestoreActorValue(ActorValue::kHealth, kHealthResetTarget - damage);
        }
    }
}
