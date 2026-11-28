// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xfab960 NiPSysDragFieldModifier::IsEqual
#include "NiPSysDragFieldModifier_fab960.h"

// Compare base field modifier state, the direction flag, and the drag direction vector.
bool NiPSysDragFieldModifier::IsEqual(NiObject* a_other)
{
    if (!NiPSysFieldModifier::IsEqual(a_other)) {
        return false;
    }

    NiPSysDragFieldModifier* other = static_cast<NiPSysDragFieldModifier*>(a_other);
    return other->useDirection == useDirection &&
           other->directionX == directionX &&
           other->directionY == directionY &&
           other->directionZ == directionZ;
}
