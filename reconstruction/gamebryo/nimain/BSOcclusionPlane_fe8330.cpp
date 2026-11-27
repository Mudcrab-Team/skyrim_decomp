// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, CreateClone, CopyTransformTo, NiCloningProcess, size, updateFacesOrVertices: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe8330 BSOcclusionPlane::CreateClone
#include "BSOcclusionPlane_fe8330.h"

NiObject* BSOcclusionPlane::CreateClone(NiCloningProcess& cloning)
{
    BSOcclusionPlane* clone = new BSOcclusionPlane();
    CopyTransformTo(*clone, cloning);
    clone->size = size;
    clone->updateFacesOrVertices = true;
    return clone;
}
