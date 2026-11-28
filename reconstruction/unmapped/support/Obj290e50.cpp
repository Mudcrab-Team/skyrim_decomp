// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x290e50 Obj290e50::Function290e50
// Adapted bodies: none
#include "Obj290e50.h"

#include <cmath>

// Checks whether a qualifying reference has an effective radius exceeding the global threshold.
bool Obj290e50::Function290e50(const Ref290e50* a_ref)
{
    bool result = false;
    if (a_ref && a_ref->base40) {
        std::uint8_t type = a_ref->base40->formType;
        if (type == 0x22u || (type == 0x24u && (a_ref->base40->flags88 & 0x4u) != 0)) {
            const Bounds290e50* bounds = a_ref->extraList70.GetBounds();
            float radius;
            if (bounds) {
                radius = std::sqrt(bounds->x * bounds->x + bounds->y * bounds->y + bounds->z * bounds->z);
            } else {
                radius = a_ref->base40->GetRadius() * a_ref->GetScale();
            }
            if (radius > g_radiusThreshold290e50) {
                result = true;
            }
        }
    }
    return result;
}
