// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5c5900 DetectLifeEffect::CheckTarget
// Adapted bodies: none
#include "DetectLifeEffect_5c5900.h"

bool DetectLifeEffect::CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args)
{
    if (a_args.caster && a_args.caster == g_player && a_args.target) {
        if (a_args.target->GetOwnerActor()) {
            return true;
        }
    }
    return false;
}
