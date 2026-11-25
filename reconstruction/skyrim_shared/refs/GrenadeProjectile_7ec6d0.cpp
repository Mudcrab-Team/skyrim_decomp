// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7ec6d0 GrenadeProjectile::IsLive
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "GrenadeProjectile_7ec6d0.h"

bool GrenadeProjectile::IsLive()
{
    return TestBit(baseForm->baseFlags, 2) && 0.0f < baseForm->baseDuration;
}
