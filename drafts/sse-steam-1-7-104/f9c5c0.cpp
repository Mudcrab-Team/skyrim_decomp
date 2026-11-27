// Near miss: 7.0 alignment distance | register-schedule
// Exposure detail: (community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled declarations
// NiPSysGravityModifier: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysGravityModifier::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf9c5c0 NiPSysGravityModifier::IsEqual

#include "include/f9c5c0/NiPSysGravityModifier_f9c5c0.h"

bool NiPSysGravityModifier::IsEqual(NiObjectRef* object)
{
    if (!NiPSysModifier::IsEqual(object))
        return false;
    auto* other = static_cast<NiPSysGravityModifier*>(object);
    if (gravityObj) {
        if (!other->gravityObj || !gravityObj->vtable->isEqual(gravityObj, other->gravityObj))
            return false;
    } else if (other->gravityObj) {
        return false;
    }
    if (gravityAxis.x != other->gravityAxis.x ||
        gravityAxis.y != other->gravityAxis.y ||
        gravityAxis.z != other->gravityAxis.z ||
        decay != other->decay || strength != other->strength ||
        other->forceType != forceType || turbulence != other->turbulence ||
        scale != other->scale || other->worldAligned != worldAligned)
        return false;
    return true;
}
