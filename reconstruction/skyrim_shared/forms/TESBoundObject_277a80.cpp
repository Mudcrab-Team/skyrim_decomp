// Source exposure: mixed (community declarations; permitted sibling exposure; pinned-image observations).
// Code origin: original; target-observed signed-short diagonal calculation
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x277a80 TESBoundObject::Function277a80
// Adapted bodies: none
#include "TESBoundObject_277a80.h"
#include <cmath>

float TESBoundObject::Function277a80()
{
    NiNPShortPoint3 diagonal(
        static_cast<int16_t>(boundData.boundMin.x - boundData.boundMax.x),
        static_cast<int16_t>(boundData.boundMin.y - boundData.boundMax.y),
        static_cast<int16_t>(boundData.boundMin.z - boundData.boundMax.z));
    return std::sqrt(static_cast<float>(diagonal.x * diagonal.x + diagonal.y * diagonal.y + diagonal.z * diagonal.z)) * 0.5f;
}
