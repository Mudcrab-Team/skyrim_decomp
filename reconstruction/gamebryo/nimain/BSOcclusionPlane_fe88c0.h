// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSOcclusionPlane, GetCorners: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateCorners, corners: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint3.h"

class BSOcclusionPlane
{
public:
    void GetCorners(NiPoint3* destination);

private:
    void UpdateCorners();
    unsigned char unknown00[0xc0];
    NiPoint3 corners[4];
};
