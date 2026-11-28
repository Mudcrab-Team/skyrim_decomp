// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x2d47d0 Obj2d47d0::CompareDistance
// Adapted bodies: none
#include "Obj2d47d0.h"

// Guess: compare the squared distance between two 3D points against a squared radius.
int Obj2d47d0::CompareDistance(const Obj2d47d0& a_other, float a_radius) const
{
    const float dx = m_x - a_other.m_x;
    const float dy = m_y - a_other.m_y;
    const float dz = m_z - a_other.m_z;
    const float distSq = dy * dy + dx * dx + dz * dz;
    const float radiusSq = a_radius * a_radius;
    if (distSq < radiusSq)
    {
        return -1;
    }
    return distSq > radiusSq ? 1 : 0;
}
