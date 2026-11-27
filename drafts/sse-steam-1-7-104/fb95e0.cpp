// Near miss: 5.0 alignment distance | register-schedule
// Exposure detail: (pinned-image observations; community-generated names).
// Source exposure: mixed
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xfb95e0 NiPSysSpawnModifier::IsEqual

#include "include/fb95e0/NiPSysSpawnModifier_fb95e0.h"

bool NiPSysSpawnModifier::IsEqual(NiObject* object)
{
    NiPSysSpawnModifier* other;
    if (!NiPSysModifier::IsEqual(object))
        return false;
    other = static_cast<NiPSysSpawnModifier*>(object);
    if (other->generations != generations)
        return false;
    if (percentage != other->percentage)
        return false;
    if (other->minimum != minimum)
        return false;
    if (other->maximum != maximum) {
        return false; } else {
    if (speedChaos != other->speedChaos)
        return false;
    if (directionChaos != other->directionChaos)
        return false;
    if (lifeSpan != other->lifeSpan)
        return false;
    if (lifeSpanVariance != other->lifeSpanVariance) {
        return false; } else {
    return true;
}
}
}
