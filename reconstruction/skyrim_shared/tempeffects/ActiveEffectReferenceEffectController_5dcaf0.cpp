// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5dcaf0 ActiveEffectReferenceEffectController::GetAllowNo3D
// Adapted bodies: none
#include "ActiveEffectReferenceEffectController_5dcaf0.h"

bool ActiveEffectReferenceEffectController::GetAllowNo3D()
{
    bool result = false;
    if (effect && effect->target) {
        TESObjectREFR* ref = effect->target->GetTargetStatsObject();
        result = ref && ref->Get3D2();
    }
    return result;
}
