// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShadowmapDescriptor; size 0xf0
#pragma once

#include "NiFrustumPlanes.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
#include "NiRect_int_2e835157.h"
#include "XMFLOAT4X4.h"
struct BSCullingProcess;
struct ShadowmapDescriptor {
    XMFLOAT4X4 lightTransform;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    NiPointer_RE__BSShaderAccumulator_c0b65593 shaderAccumulator;
    unsigned int cullingMode;
    unsigned char renderTarget_raw[4];
    unsigned int shadowmapIndex;
    NiFrustumPlanes clipPlanes;
    unsigned int unitsPerTexel;
    NiRect_int_2e835157 port;
    BSCullingProcess* cullingProcess;
    bool clearRenderTarget;
    bool isEnabled;
    unsigned char undefined_ea[6];
};
static_assert(sizeof(ShadowmapDescriptor) == 240, "ShadowmapDescriptor layout differs from the PDB");
