// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x1203cd0 Object1203cd0::Object1203cd0
// CI hash: 0x1203cd0 ??0Object1203cd0@@QEAA@PEAXPEBUVec3_1203cd0@@@Z
// Adapted bodies: none
#include "Object1203cd0.h"

// Constructs Base1203cd0(owner), copies *pos into position, clears ptr30, and clears flag2B.
Object1203cd0::Object1203cd0(void* owner, const Vec3_1203cd0* pos)
    : Base1203cd0(owner)
{
    position.x = pos->x;
    position.y = pos->y;
    position.z = pos->z;
    ptr30 = nullptr;
    flag2B = false;
}
