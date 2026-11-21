// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCullingProcess; size 0x128
#pragma once

#include "NiFrustum.h"
#include "NiFrustumPlanes.h"
struct NiCamera;
struct NiCullingProcess_vtbl;
struct NiVisibleArray;
struct NiCullingProcess {
    NiCullingProcess_vtbl* __vftable;
    bool useVirtualAppend;
    unsigned char pad009;
    unsigned short pad00A;
    unsigned int pad00C;
    NiVisibleArray* visibleSet;
    NiCamera* camera;
    NiFrustum frustum;
    NiFrustumPlanes planes;
    NiFrustumPlanes customCullPlanes;
    bool cameraRelatedUpdates;
    bool updateAccumulateFlag;
    bool ignorePreprocess;
    bool doCustomCullPlanes;
    bool enablePlaneOptimization;
    unsigned char unk121;
    unsigned short pad122;
    unsigned int pad124;
};
static_assert(sizeof(NiCullingProcess) == 296, "NiCullingProcess layout differs from the PDB");
