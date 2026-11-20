// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiMultiTargetTransformController; size 0x60
#pragma once

#include "NiInterpController_473343fb.h"
struct NiAVObject;
struct NiBlendTransformInterpolator;
struct NiMultiTargetTransformController {
    NiInterpController_473343fb _base;
    NiBlendTransformInterpolator* blendInterps;
    NiAVObject** targets;
    unsigned short numInterps;
    unsigned short pad5A;
    unsigned int pad5C;
};
static_assert(sizeof(NiMultiTargetTransformController) == 96, "NiMultiTargetTransformController layout differs from the PDB");
