// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionBox, CreateClone, CopyTransformTo, NiCloningProcess, size, updateFacesOrVertices: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe5aa0 BSOcclusionBox::CreateClone
#include "BSOcclusionBox_fe5aa0.h"

NiObject* BSOcclusionBox::CreateClone(NiCloningProcess& cloning)
{
    BSOcclusionBox* clone = new BSOcclusionBox();
    CopyTransformTo(*clone, cloning);
    clone->size.x = size.x;
    clone->size.y = size.y;
    clone->size.z = size.z;
    clone->updateFacesOrVertices = true;
    return clone;
}
