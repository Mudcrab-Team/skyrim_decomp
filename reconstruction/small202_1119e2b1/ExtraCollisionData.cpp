// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraCollisionData: EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x186630 ExtraCollisionData::~ExtraCollisionData
#include "ExtraCollisionData.h"
ExtraCollisionData::~ExtraCollisionData() {
 FreeCollision(collisionData, sizeof(CollisionData));
}
