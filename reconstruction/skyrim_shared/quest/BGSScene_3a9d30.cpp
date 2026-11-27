// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3a9d30 BGSScene::Function3a9d30
// Adapted bodies: none
#include "BGSScene_3a9d30.h"

int BGSScene::Function3a9d30(BGSSceneAction* action)
{
    if (action) {
        if ((action->actionFlags & 1) || action->Function3ab0f0(currentPhase)) {
            if (aliasID == action->phaseID) {
                action->vfunc16(parentScene);
                action->actionFlags &= ~2;
            }
        }
    }
    return 1;
}
