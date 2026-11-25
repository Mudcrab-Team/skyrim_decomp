// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Code origin: original reconstruction from the pinned image listing; names as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5dc9e0 ActiveEffectReferenceEffectController::EffectShouldFaceTarget
#include "ActiveEffectReferenceEffectController_5dc9e0.h"

bool ActiveEffectReferenceEffectController::EffectShouldFaceTarget()
{
    if (owner && GetEffectRefData(owner) && GetEffectRefData(owner)->art) {
        if (GetEffectRefData(owner)->art->flags & 1) {
            return true;
        }
    }
    return false;
}
