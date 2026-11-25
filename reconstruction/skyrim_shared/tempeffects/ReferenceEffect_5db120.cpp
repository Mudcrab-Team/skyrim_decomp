// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below; offsets and the base call checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:86
// 0x5db120 ReferenceEffect::~ReferenceEffect
#include "ReferenceEffect_5db120.h"

// Drop the handles, tell the controller this effect is gone and free the controller when the effect owns it.
ReferenceEffect::~ReferenceEffect()
{
    target.iBits = BSUntypedPointerHandle::hNull.iBits;
    aimAtTarget.iBits = BSUntypedPointerHandle::hNull.iBits;
    if (controller) {
        controller->RemoveHitEffect(this);
        if (ownController) {
            if (controller) {
                delete controller;
            }
        }
    }
    controller = nullptr;
}
