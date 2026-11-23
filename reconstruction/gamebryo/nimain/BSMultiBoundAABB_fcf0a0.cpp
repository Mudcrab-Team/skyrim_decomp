// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfcf0a0 BSMultiBoundAABB::IsInsideFrustumPlanes
// Adapted bodies: none
#include "BSMultiBoundAABB_fcf0a0.h"

#include <cmath>
#include <cstddef>

// Project, IsOutsidePlane, PlaneCursor, index, bit, Advance, IsActive: GUESS(low)
inline float Project(const NiPoint3& a_left, const NiPoint3& a_right)
{
    return a_left.x * a_right.x + a_left.y * a_right.y + a_left.z * a_right.z;
}

inline bool IsOutsidePlane(const BSMultiBoundPlanes::Plane& a_plane, const NiPoint3& a_center, const NiPoint3& a_size)
{
    const NiPoint3 normal{
        std::fabs(a_plane.normal.x), std::fabs(a_plane.normal.y), std::fabs(a_plane.normal.z)
    };
    return Project(a_plane.normal, a_center) - Project(normal, a_size) < a_plane.distance;
}

struct PlaneCursor
{
    std::ptrdiff_t index;
    std::uint32_t bit;

    void Advance()
    {
        ++index;
        bit <<= 1;
    }

    bool IsActive(std::uint32_t a_active) const
    {
        std::uint32_t selected = bit;
        selected &= a_active;
        return selected != 0;
    }
};

bool BSMultiBoundAABB::IsInsideFrustumPlanes(const BSMultiBoundPlanes& a_planes) const
{
    for (PlaneCursor cursor{ 0, 1 }; cursor.index < 6; cursor.Advance()) {
        if (cursor.IsActive(a_planes.mask) && IsOutsidePlane(a_planes.planes[cursor.index], center, size)) {
            return false;
        }
    }
    return true;
}
