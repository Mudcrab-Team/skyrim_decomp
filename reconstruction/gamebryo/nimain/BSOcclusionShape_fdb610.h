// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSOcclusionShape, CopyTransformTo: CRASHLOGGER_PDB(59818@2026.10.24)
// translation, rotation, visibilityState, updateFacesOrVertices: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint3.h"
#include "generated/crashlogger_pdb/types/NiMatrix3.h"

class BSOcclusionShape
{
public:
    void CopyTransformTo(BSOcclusionShape& destination) const;

private:
    unsigned char unknown00[0x10];
    NiPoint3 translation;
    NiMatrix3 rotation;
    unsigned int visibilityState;
    bool updateFacesOrVertices;
};
