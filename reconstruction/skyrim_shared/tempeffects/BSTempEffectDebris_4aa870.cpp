// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x4aa870 BSTempEffectDebris::AddtoDebrisCounter
#include "BSTempEffectDebris_4aa870.h"

void BSTempEffectDebris::AddtoDebrisCounter(BSTempEffectDebris* a_debris)
{
    if (!a_debris) {
        return;
    }

    gDebrisList.AddTail(a_debris);
}
