// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: original reconstruction from the pinned image listing; names as labelled below.
// SPDX-License-Identifier: CC0-1.0
// ValueModifierEffect, SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// Sibling source: momusdigital/fnv_decomp@91e1b6e src/fallout/magic/valuemodifiereffect.h:24
// SetExplosionLocation: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: SetActorValue follows fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6 (author permission); the same one-line setter is in momusdigital/fnv_decomp@91e1b6e src/fallout/magic/valuemodifiereffect.h:24.
// 0x5e6fc0 ValueModifierEffect::CheckTarget
#include "ValueModifierEffect_5e6fc0.h"

bool ValueModifierEffect::CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args)
{
    if (a_args.target) {
        if (auto* actor = a_args.target->GetOwnerActor()) {
            if (!actor->IsDead(true)) {
                return true;
            }
        }
    }
    return false;
}
