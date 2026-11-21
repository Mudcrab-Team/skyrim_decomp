// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDecalManager; size 0x90
#pragma once

#include "BSTArray_RE__NiPointer_RE__BGSDecalEmitter_067ff20b.h"
#include "BSTArray_RE__NiPointer_RE__BGSDecalNode_5ea3816e.h"
#include "BSTArray_RE__NiPointer_RE__BSTempEffectSimpleDecal_a9d17341.h"
#include "BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BGSDecalManager {
    unsigned int unk00;
    unsigned int decalCountCurrentFrame;
    unsigned int skinDecalCountCurrentFrame;
    unsigned int decalCount;
    unsigned int skinDecalCount;
    bool unk14;
    unsigned char pad15;
    unsigned short pad16;
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d decals;
    BSTArray_RE__NiPointer_RE__BGSDecalEmitter_067ff20b decalEmitters;
    BSTArray_RE__NiPointer_RE__BGSDecalNode_5ea3816e decalNodes;
    BSTArray_RE__NiPointer_RE__BSTempEffectSimpleDecal_a9d17341 simpleDecals;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    NiPointer_RE__BSShaderAccumulator_c0b65593 shaderAccumulator;
    unsigned int unk88;
    unsigned char undefined_8c[4];
};
static_assert(sizeof(BGSDecalManager) == 144, "BGSDecalManager layout differs from the PDB");
