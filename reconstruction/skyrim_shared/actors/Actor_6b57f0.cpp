// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x6b57f0 Actor::GetPositionOrZero6b57f0
// Adapted bodies: none
#include "Actor_6b57f0.h"

#include <cfloat>

void Actor::GetPositionOrZero6b57f0(Vec3* out) const
{
    const Vec3* source = reinterpret_cast<const Vec3*>(reinterpret_cast<const char*>(this) - 0x78);
    float x = source->x;
    out->x = x;
    out->y = source->y;
    out->z = source->z;
    if (x == FLT_MAX) {
        out->x = 0.0f;
    }
}
