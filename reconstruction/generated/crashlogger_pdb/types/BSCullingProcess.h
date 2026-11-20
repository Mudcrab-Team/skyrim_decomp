// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCullingProcess; size 0x301f8
#pragma once

#include "BSCPCullingType.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "NiFrustum.h"
#include "NiFrustumPlanes.h"
struct BSCompoundFrustum;
struct BSCullingProcess_vtbl;
struct BSPortalGraphEntry;
struct NiCamera;
struct NiVisibleArray;
struct BSCullingProcess {
    BSCullingProcess_vtbl* __vftable;
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
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101 objectArray;
    unsigned char cullQueue[196640];
    unsigned char roomSharedMap[48];
    BSPortalGraphEntry* portalGraphEntry;
    BSCPCullingType cullMode;
    unsigned int pad3019C;
    BSCompoundFrustum* compoundFrustum;
    BSCPCullingType cullModeStack[10];
    unsigned int cullModeStackIndex;
    bool recurseToGeometry;
    bool isGroupingAlphas;
    unsigned char unk301D6;
    unsigned char pad301D7;
    BSTArray_void_9eb8914c_e1846db0 alphaGroups;
    int alphaGroupIndex;
    unsigned int alphaGroupStopIndex;
};
static_assert(sizeof(BSCullingProcess) == 197112, "BSCullingProcess layout differs from the PDB");
