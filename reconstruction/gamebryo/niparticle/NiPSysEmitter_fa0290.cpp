// Source exposure: mixed (community declarations; local target observations).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfa0290 NiPSysEmitter::IsEqual
// Adapted bodies: none
#include "NiPSysEmitter_fa0290.h"

// Compares the base modifier and each streamed emitter scalar.
bool NiPSysEmitter::IsEqual(NiObject* object)
{
    if (!NiPSysModifier::IsEqual(object)) {
        return false;
    }
    NiPSysEmitter* other = static_cast<NiPSysEmitter*>(object);
    if (other->speed != speed) {
        return false;
    }
    if (other->speedVariance != speedVariance) {
        return false;
    }
    if (other->declination != declination) {
        return false;
    }
    if (other->declinationVariance != declinationVariance) {
        return false;
    }
    if (other->planarAngle != planarAngle) {
        return false;
    }
    if (other->planarAngleVariance != planarAngleVariance) {
        return false;
    }
    if (other->initialColor[0] != initialColor[0]) {
        return false;
    }
    if (other->initialColor[1] != initialColor[1]) {
        return false;
    }
    if (other->initialColor[2] != initialColor[2]) {
        return false;
    }
    if (other->initialColor[3] != initialColor[3]) {
        return false;
    }
    if (other->initialRadius != initialRadius) {
        return false;
    }
    if (other->radiusVariance != radiusVariance) {
        return false;
    }
    if (other->lifeSpan != lifeSpan) {
        return false;
    }
    if (other->lifeSpanVariance != lifeSpanVariance) {
        return false;
    }
    return true;
}
