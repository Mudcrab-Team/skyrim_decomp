// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x74a6f0 ActiveEffect::AllowHitEffects
// Adapted bodies: none
#include "ActiveEffect_74a6f0.h"

bool ActiveEffect::AllowHitEffects()
{
    Actor* owner = target->GetOwnerActor();
    if (owner && owner == g_player && g_hitEffectSource->count > 0 && g_hitEffectCounter >= 0) {
        bool first = g_hitEffectCounter == 0;
        g_hitEffectCounter++;
        return first;
    }
    return true;
}
