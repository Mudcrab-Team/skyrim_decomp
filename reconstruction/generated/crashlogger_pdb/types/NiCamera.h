// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCamera; size 0x188
#pragma once

#include "NiAVObject.h"
#include "NiFrustum.h"
#include "NiRect_float_834c7c37.h"
struct NiCamera {
    NiAVObject _base;
    float worldToCam[4][4];
    NiFrustum viewFrustum;
    float minNearPlaneDist;
    float maxFarNearRatio;
    NiRect_float_834c7c37 port;
    float lodAdjust;
};
static_assert(sizeof(NiCamera) == 392, "NiCamera layout differs from the PDB");
