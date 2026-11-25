// Source exposure: mixed (local binary analysis and named community declarations).
// Code origin: original body, with a scalar distance calculation.
// Recipe: reconstruction/recipes/o2-fpfast.json
// Cookbook: 48
// 0xfe58e0 BSMultiBoundSphere::GetPointWithin
#include "BSMultiBoundSphere_fe58e0.h"
#include <cmath>

// Test whether the point lies strictly inside the sphere.
bool BSMultiBoundSphere::GetPointWithin(const NiPoint3& point) const
{
    const float dx = point.x - center.x;
    const float dy = point.y - center.y;
    const float dz = point.z - center.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz) < radius;
}
