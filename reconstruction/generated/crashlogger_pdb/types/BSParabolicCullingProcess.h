// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParabolicCullingProcess; size 0x30230
#pragma once

#include "BSCullingProcess.h"
#include "NiPlane_4e79da03.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BSParabolicCullingProcess {
    BSCullingProcess _base;
    float unk301F8;
    unsigned char undefined_301fc[4];
    NiPointer_RE__BSShaderAccumulator_c0b65593 backHemisphereAccumulator;
    NiPlane_4e79da03 equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiPointer_RE__NiCamera_cf3a8333 lightCamera;
};
static_assert(sizeof(BSParabolicCullingProcess) == 197168, "BSParabolicCullingProcess layout differs from the PDB");
