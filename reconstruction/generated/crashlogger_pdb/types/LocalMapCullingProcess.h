// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LocalMapCullingProcess; size 0x30360
#pragma once

#include "BSCullingJob.h"
#include "BSCullingProcess.h"
#include "ImageSpaceShaderParam.h"
#include "LocalMapCamera.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct LocalMapCullingProcess {
    BSCullingProcess cullingProcess;
    BSCullingJob cullingJob;
    LocalMapCamera camera;
    NiPointer_RE__BSShaderAccumulator_c0b65593 accumulator;
    ImageSpaceShaderParam imageSpaceShaderParam;
    unsigned int renderTarget;
    unsigned int renderMode;
    NiPointer_RE__NiNode_28171d5b unk30358;
};
static_assert(sizeof(LocalMapCullingProcess) == 197472, "LocalMapCullingProcess layout differs from the PDB");
