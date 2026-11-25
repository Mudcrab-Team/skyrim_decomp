// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSOcclusionBox, AreCornersInsidePlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPlane, NiFrustumPlanes, corners, activePlanes, cullingPlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// normal, constant: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint3.h"

struct NiPlane
{
    NiPoint3 normal;
    float constant;
};
struct NiFrustumPlanes
{
    NiPlane cullingPlanes[6];
    unsigned int activePlanes;
};
class BSOcclusionBox
{
public:
    bool AreCornersInsidePlanes(const NiFrustumPlanes& frustum) const;
private:
    unsigned char unknown00[0x134];
    NiPoint3 corners[8];
};
