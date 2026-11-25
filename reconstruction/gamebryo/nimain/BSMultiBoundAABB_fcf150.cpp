// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xfcf150 BSMultiBoundAABB::GetBoundingSphere
// Adapted bodies: none
#include "BSMultiBoundAABB_fcf150.h"

#include <cmath>

void BSMultiBoundAABB::GetBoundingSphere(float* a_sphere) const
{
    const float x = size[0];
    const float y = size[1];
    const float z = size[2];
    const float radius = std::sqrt(x * x + y * y + z * z);
    a_sphere[0] = center[0];
    a_sphere[1] = center[1];
    a_sphere[2] = center[2];
    a_sphere[3] = radius;
}
