// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x157d1b0 BSPSysSimpleColorModifier::IsEqual
#include "BSPSysSimpleColorModifier_157d1b0.h"

bool BSPSysSimpleColorModifier::IsEqual(NiObject* a_object)
{
    if (!NiPSysModifier::IsEqual(a_object)) {
        return false;
    }

    auto* other = static_cast<BSPSysSimpleColorModifier*>(a_object);
    if (other->fadeInPercent != fadeInPercent ||
        other->fadeOutPercent != fadeOutPercent ||
        other->color1EndPercent != color1EndPercent ||
        other->color1StartPercent != color1StartPercent ||
        other->color2EndPercent != color2EndPercent ||
        other->color2StartPercent != color2StartPercent) {
        return false;
    }

    return other->colors[0] == colors[0] &&
           other->colors[1] == colors[1] &&
           other->colors[2] == colors[2];
}
