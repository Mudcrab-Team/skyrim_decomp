// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, BSOcclusionShape, CopyTransformTo, size, NiPoint2, updateFacesOrVertices, NiCloningProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyPlaneTo: GUESS(low)
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint2_6bdffc9f.h"

class NiCloningProcess;
class BSOcclusionShape
{
protected:
    void CopyTransformTo(BSOcclusionShape& destination, NiCloningProcess& cloning) const;
    unsigned char unknown00[0x44];
    bool updateFacesOrVertices;
    unsigned char unknown45[3];
};

class BSOcclusionPlane : public BSOcclusionShape
{
public:
    void CopyPlaneTo(BSOcclusionPlane& destination, NiCloningProcess& cloning) const;

private:
    NiPoint2_6bdffc9f size;
};
