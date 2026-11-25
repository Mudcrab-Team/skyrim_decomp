// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xffdf10 BSProceduralLightningController::Functionffdf10
// Adapted bodies: none
#include "BSProceduralLightningController_ffdf10.h"

// Replaces the owned object at unk180, deleting the old one.
void BSProceduralLightningController::Functionffdf10(Payload* a_new)
{
    delete unk180;
    unk180 = a_new;
}
