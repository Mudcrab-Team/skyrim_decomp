// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x186670 ExtraCollisionData::IsNotEqual
// Adapted bodies: none
#include "ExtraCollisionData_186670.h"
bool ExtraCollisionData::IsNotEqual(const ExtraCollisionData* other) const
{
    const CollisionData* a = collisionData;
    const CollisionData* b = other->collisionData;
    if (!a && !b) return false;
    if (!a || !b) return true;
    if (a->id != b->id) return true;
    return false;
}
