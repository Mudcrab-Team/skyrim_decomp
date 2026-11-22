// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5e3000 SummonCreatureEffect::ClearTargetImpl
// Adapted bodies: none
#include "SummonCreatureEffect_5e3000.h"

void SummonCreatureEffect::ClearTargetImpl()
{
    if (summonPlacementEffect) {
        summonPlacementEffect->unk30 = nullptr;
    }
    if (target) {
        target->InvalidateCommandedActorEffect(this);
    }
    ActiveEffect::ClearTargetImpl();
}
