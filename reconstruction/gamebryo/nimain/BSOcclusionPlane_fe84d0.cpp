// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, BSOcclusionShape, CopyTransformTo, size, NiPoint2, updateFacesOrVertices, NiCloningProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyPlaneTo: GUESS(low)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfe84d0 BSOcclusionPlane::CopyPlaneTo
// CI hash: 0xfe84d0 ?CopyPlaneTo@BSOcclusionPlane@@QEBAXAEAV1@AEAVNiCloningProcess@@@Z
#include "BSOcclusionPlane_fe84d0.h"

// A resized clone needs fresh face geometry even after its transform has been copied.
void BSOcclusionPlane::CopyPlaneTo(BSOcclusionPlane& destination, NiCloningProcess& cloning) const
{
    CopyTransformTo(destination, cloning);
    destination.size = size;
    destination.updateFacesOrVertices = true;
}
