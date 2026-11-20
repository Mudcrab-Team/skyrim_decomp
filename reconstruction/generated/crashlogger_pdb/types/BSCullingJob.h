// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCullingJob; size 0x68
#pragma once

#include "Enum_RE__BSCullingProcess__BSCPCullingType_a98afb9b.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BSCompoundFrustum;
struct BSCullingProcess;
struct BSPortalGraphEntry;
struct NiFrustum;
struct NiFrustumPlanes;
struct RE__BSTArray_RE__NiAVObject_cce16074;
struct BSCullingJob {
    NiPointer_RE__BSShaderAccumulator_c0b65593 accumulator;
    NiPointer_RE__BSShaderAccumulator_c0b65593 secondAccumulator;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    BSCompoundFrustum* compoundFrustum;
    NiFrustum* frustum;
    BSPortalGraphEntry* portalGraphEntry;
    BSCullingProcess* cullingProcess;
    NiFrustumPlanes* frustumPlanes;
    NiPointer_RE__NiAVObject_9e3aa701 scene;
    RE__BSTArray_RE__NiAVObject_cce16074* accumulatedObjectArray;
    Enum_RE__BSCullingProcess__BSCPCullingType_a98afb9b cullMode;
    unsigned int unk54;
    unsigned int jobIndex;
    bool unk5C;
    bool processingDirectionalLight;
    bool ignorePreprocess;
    bool usingCustomCullPlanes;
    bool unk60;
    bool respectHidden;
    bool unk62;
    unsigned char pad63[5];
};
static_assert(sizeof(BSCullingJob) == 104, "BSCullingJob layout differs from the PDB");
