// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a7270 TES::FlipCollision
// Adapted bodies: none
#include "TES_1a7270.h"

void TES::FlipCollision()
{
    bool state = !gToggleState;
    gToggleState = state;
    bhkWorld* world;
    if (gTES->interiorCell) {
        world = gTES->interiorCell->GetbhkWorld();
    } else {
        world = *gExteriorbhkWorld;
    }
    bool disabled = !state;
    if (world) {
        world->collisionDisabled = disabled;
    }
    gCollisionDisabled = disabled;
}
