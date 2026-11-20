// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OcclusionMapData; size 0x60
#pragma once

#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
#include "XMFLOAT4X4.h"
struct BSGeometryListCullingProcess;
struct OcclusionMapData {
    XMFLOAT4X4 projection;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    NiPointer_RE__BSShaderAccumulator_c0b65593 accumulator;
    BSGeometryListCullingProcess* cullingProcess;
    unsigned long long pad58;
};
static_assert(sizeof(OcclusionMapData) == 96, "OcclusionMapData layout differs from the PDB");
