// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderProperty; size 0x88
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTSmartPointer_RE__BSEffectShaderData_084c1468.h"
#include "EShaderPropertyFlag.h"
#include "NiShadeProperty_84fb882d.h"
#include "RenderPassArray.h"
struct BSFadeNode;
struct BSShaderMaterial_da61c263;
struct BSShaderPropertyLightData_d731fdd1;
struct BSShaderProperty_a291ab3c {
    NiShadeProperty_84fb882d _base;
    float alpha;
    int lastRenderPassState;
    EShaderPropertyFlag flags;
    unsigned char _pad_0[4];
    RenderPassArray renderPassList;
    RenderPassArray debugRenderPassList;
    BSFadeNode* fadeNode;
    BSTSmartPointer_RE__BSEffectShaderData_084c1468 effectData;
    BSShaderPropertyLightData_d731fdd1* lightData;
    BSShaderMaterial_da61c263* material;
    unsigned int lastAccumulatedFrameCount;
    unsigned char undefined_84[4];
};
static_assert(sizeof(BSShaderProperty_a291ab3c) == 136, "BSShaderProperty_a291ab3c layout differs from the PDB");
