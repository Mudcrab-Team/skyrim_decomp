// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x213340 Unit213340::ContainsPoint213340
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "Unit213340.h"

// Returns true when a_point lies within the symmetric axis-aligned box [-bounds, +bounds].
bool Unit213340::ContainsPoint213340(const Vec213340& a_point) const
{
    return a_point.x >= -bounds.x &&
           a_point.y >= -bounds.y &&
           a_point.z >= -bounds.z &&
           a_point.x <= bounds.x &&
           a_point.y <= bounds.y &&
           a_point.z <= bounds.z;
}
