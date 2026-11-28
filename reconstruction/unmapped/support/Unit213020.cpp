// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x213020 Unit213020::ContainsPoint213020
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "Unit213020.h"

// Returns true when a_point lies within the symmetric axis-aligned box [-bounds, +bounds].
bool Unit213020::ContainsPoint213020(const Vec213020& a_point) const
{
    return a_point.x >= -bounds.x &&
           a_point.y >= -bounds.y &&
           a_point.z >= -bounds.z &&
           a_point.x <= bounds.x &&
           a_point.y <= bounds.y &&
           a_point.z <= bounds.z;
}
