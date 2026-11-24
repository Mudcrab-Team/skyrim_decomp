// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a72d0 TES::SetCollisionEnabled
// Adapted bodies: none
#include "TES_1a72d0.h"

void TES::SetCollisionEnabled(bool enabled)
{
    bhkWorld* world;
    if (gTES->interiorCell) {
        world = gTES->interiorCell->GetbhkWorld();
    } else {
        world = *gExteriorbhkWorld;
    }
    bool disabled = !enabled;
    if (world) {
        world->collisionDisabled = disabled;
    }
    gCollisionDisabled = disabled;
}
