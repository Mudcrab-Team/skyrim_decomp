// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderProperty; size 0x88
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTSmartPointer_RE__BSEffectShaderData_084c1468.h"
#include "EShaderPropertyFlag.h"
#include "NiShadeProperty.h"
#include "RenderPassArray.h"
struct BSFadeNode_d765e32e;
struct BSShaderMaterial;
struct BSShaderPropertyLightData;
struct BSShaderProperty {
    NiShadeProperty _base;
    float alpha;
    int lastRenderPassState;
    EShaderPropertyFlag flags;
    unsigned char _pad_0[4];
    RenderPassArray renderPassList;
    RenderPassArray debugRenderPassList;
    BSFadeNode_d765e32e* fadeNode;
    BSTSmartPointer_RE__BSEffectShaderData_084c1468 effectData;
    BSShaderPropertyLightData* lightData;
    BSShaderMaterial* material;
    unsigned int lastAccumulatedFrameCount;
    unsigned char undefined_84[4];
};
static_assert(sizeof(BSShaderProperty) == 136, "BSShaderProperty layout differs from the PDB");
