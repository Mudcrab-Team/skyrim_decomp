// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCubeMapCamera; size 0x1c8
#pragma once

#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101.h"
#include "NiCamera.h"
#include "NiColorA.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BSCubeMapCamera {
    NiCamera _base;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101 scenes;
    NiPointer_RE__BSShaderAccumulator_c0b65593 accumulator;
    NiPointer_RE__BSShaderAccumulator_c0b65593 secondAccumulator;
    NiPointer_RE__NiCamera_cf3a8333 unk1B0;
    NiColorA silhouetteColor;
};
static_assert(sizeof(BSCubeMapCamera) == 456, "BSCubeMapCamera layout differs from the PDB");
