// Source exposure: mixed (pinned image; cited community declarations and symbol layouts).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0xfa6f70 NiPSysBombModifier::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiPSysBombModifier_fa6f70.h"

bool NiPSysBombModifier::IsEqual(NiObject* object)
{
    if (!NiPSysModifier::IsEqual(object))
        return false;
    auto other = static_cast<NiPSysBombModifier*>(object);
    if (bombObject) {
        if (!other->bombObject || !bombObject->IsEqual(other->bombObject))
            return false;
    } else if (other->bombObject) {
        return false;
    }
    return bombAxis[0] == other->bombAxis[0] &&
           bombAxis[1] == other->bombAxis[1] &&
           bombAxis[2] == other->bombAxis[2] &&
           decay == other->decay && deltaV == other->deltaV &&
           decayType == other->decayType && symmetryType == other->symmetryType;
}
