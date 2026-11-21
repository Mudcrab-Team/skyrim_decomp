// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinData; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_NiSkinPartition_7fdd996f.h"
#include "NiTransform_333059e5.h"
struct NiSkinData__BoneData;
struct NiSkinData__VFTable;
struct NiSkinData {
    NiSkinData__VFTable* vftable;
    char _pad_8[8];
    NiPointer_NiSkinPartition_7fdd996f skinPartition;
    NiTransform_333059e5 rootParentToSkin;
    char _pad_4C[4];
    NiSkinData__BoneData* boneData;
    unsigned int boneCount;
    unsigned int pad5C;
};
static_assert(sizeof(NiSkinData) == 96, "NiSkinData layout differs from the PDB");
