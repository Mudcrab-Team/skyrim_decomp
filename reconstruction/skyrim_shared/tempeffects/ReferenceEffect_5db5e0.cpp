// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5db5e0 ReferenceEffect::Detach
// Adapted bodies: none
#include "ReferenceEffect_5db5e0.h"

void ReferenceEffect::Detach()
{
    DetachImpl();
    if (controller) {
        controller->RemoveHitEffect(this);
        if (ownController && controller) {
            delete controller;
        }
    }
    controller = nullptr;
}
