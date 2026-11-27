// Source exposure: mixed (community PDB names; pinned-image observations).
// Code origin: original; handwritten null-guarded scalar equality query
// SPDX-License-Identifier: CC0-1.0
// 0xf10ab0 NiColorExtraData::Functionf10ab0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "NiColorExtraData_f10ab0.h"

bool NiColorExtraData::Functionf10ab0(const NiColorExtraData* other) const
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
