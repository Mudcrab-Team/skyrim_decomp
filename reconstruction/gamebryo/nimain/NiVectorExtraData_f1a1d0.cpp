// Source exposure: mixed (community PDB names; pinned-image observations).
// Code origin: original; handwritten null-guarded scalar equality query
// SPDX-License-Identifier: CC0-1.0
// 0xf1a1d0 NiVectorExtraData::Functionf1a1d0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "NiVectorExtraData_f1a1d0.h"

bool NiVectorExtraData::Functionf1a1d0(const NiVectorExtraData* other) const
{
    if (!other) {
        return false;
    }
    if (component0 != other->component0 || component1 != other->component1 ||
        component2 != other->component2 || component3 != other->component3) {
        return false;
    }
    return true;
}
