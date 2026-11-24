// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x301a50 TESObjectREFR::Function301a50
// Adapted bodies: none
#include "TESObjectREFR_301a50.h"

Point3* TESObjectREFR::Function301a50()
{
    TrackedPoint* tracked = nullptr;
    if (baseObject == gKindA || baseObject == gKindB) {
        tracked = extraList.Function16a760();
    }
    PrimitiveData* primitive = extraList.GetPrimitive();
    if (primitive) {
        if (tracked) {
            float x = primitive->point.x;
            float y = primitive->point.y;
            float z = primitive->point.z;
            if (x != tracked->point.x || y != tracked->point.y || z != tracked->point.z) {
                tracked->point.x = x;
                tracked->point.y = y;
                tracked->point.z = z;
            }
        }
        return &primitive->point;
    }
    return tracked ? &tracked->point : &gDefaultPoint;
}
