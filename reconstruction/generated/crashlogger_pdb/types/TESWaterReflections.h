// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterReflections; size 0x88
#pragma once

#include "NiPlane_4e79da03.h"
#include "NiPointer_RE__BSCubeMapCamera_6de3934e.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiRefObject_f24a9221.h"
struct BSCullingProcess;
struct BSWaterShaderMaterial_a6438530;
struct TESWaterReflections {
    NiRefObject_f24a9221 _base;
    unsigned short flags;  // Flags in the PDB is wider than this slot
    unsigned short pad12;
    NiPlane_4e79da03 reflectPlane;
    unsigned int pad24;
    NiPointer_RE__BSCubeMapCamera_6de3934e cubeMapCamera;
    NiPointer_RE__BSShaderAccumulator_c0b65593 sorter;
    BSCullingProcess* cullingProcess;
    BSWaterShaderMaterial_a6438530* waterMaterial;
    float reflectionUpdateTimer;
    unsigned int currentCubeMapFace;
    unsigned char cubeMapSides_raw[48];
    bool activeThisFrame;
    unsigned char pad81;
    unsigned short pad82;
    unsigned int pad84;
};
static_assert(sizeof(TESWaterReflections) == 136, "TESWaterReflections layout differs from the PDB");
