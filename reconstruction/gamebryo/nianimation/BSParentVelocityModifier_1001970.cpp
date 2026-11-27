// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSParentVelocityModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSParentVelocityModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x1001970 BSParentVelocityModifier::IsEqual
#include "BSParentVelocityModifier_1001970.h"

// Compare the base particle modifier and the damping factor.
bool BSParentVelocityModifier::IsEqual(NiPSysModifier* a_other)
{
    bool equal = NiPSysModifier::IsEqual(a_other);
    if (equal) {
        auto* other = static_cast<BSParentVelocityModifier*>(a_other);
        equal = (other->damping == damping);
    }

    return equal;
}
