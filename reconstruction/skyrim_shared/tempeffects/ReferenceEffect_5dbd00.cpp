// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5dbd00 ReferenceEffect::ClearController
// Adapted bodies: ReferenceEffect::ClearController (shape only)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffect.cpp:181
#include "ReferenceEffect_5dbd00.h"

void ReferenceEffect::ClearController()
{
    if (controller) {
        controller->RemoveHitEffect(this);
        if (ownController && controller) {
            delete controller;
        }
    }
    controller = nullptr;
}
