// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; pinned-image observations only
// SPDX-License-Identifier: CC0-1.0
// 0xf85a50 NiQuaternionInterpolator::Functionf85a50
// Adapted bodies: none
// Cookbook: 0xf85a50 2, 48
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiQuaternionInterpolator_f85a50.h"

bool NiQuaternionInterpolator::Functionf85a50() const
{
    if (data == 0) {
        return value.w != invalidQuaternion.w || value.x != invalidQuaternion.x ||
               value.y != invalidQuaternion.y || value.z != invalidQuaternion.z;
    } else {
        return false;
    }
}
