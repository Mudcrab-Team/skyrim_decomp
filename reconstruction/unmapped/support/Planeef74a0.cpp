// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Planeef74a0::Planeef74a0, treated as adapted: shaped like NiPlane::NiPlane in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/console/nipoint3.inl:58
// SPDX-License-Identifier: CC0-1.0
// 0xef74a0 Planeef74a0::Planeef74a0
#include "Planeef74a0.h"

// Constructs a plane from a normal vector and a point on the plane.
Planeef74a0::Planeef74a0(const Point3ef74a0& a_normal, const Point3ef74a0& a_point)
{
    normal.x = a_normal.x;
    normal.y = a_normal.y;
    normal.z = a_normal.z;
    constant = a_normal.x * a_point.x + a_point.y * a_normal.y + a_point.z * a_normal.z;
}
