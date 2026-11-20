// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinInstance; size 0x88
// one of 2 different PDB types sharing this name
#pragma once

#include "CRITICAL_SECTION.h"
#include "NiObject.h"
#include "NiPointer_NiSkinData_721400cb.h"
#include "NiPointer_NiSkinPartition_7fdd996f.h"
struct NiAVObject_968dc716;
struct NiTransform_333059e5;
struct NiSkinInstance_04782f6b {
    NiObject _base;
    NiPointer_NiSkinData_721400cb skinData;
    NiPointer_NiSkinPartition_7fdd996f skinPartition;
    NiAVObject_968dc716* rootParent;
    NiAVObject_968dc716** bones;
    NiTransform_333059e5** boneWorldTransforms;
    unsigned int frameID;
    int numMatrices;
    int numRegisters;
    int allocatedSize;
    void* boneMatrices;
    void* prevBoneMatrices;
    void* skinToWorldWorldToSkinMatrix;
    CRITICAL_SECTION lock;
};
static_assert(sizeof(NiSkinInstance_04782f6b) == 136, "NiSkinInstance_04782f6b layout differs from the PDB");
