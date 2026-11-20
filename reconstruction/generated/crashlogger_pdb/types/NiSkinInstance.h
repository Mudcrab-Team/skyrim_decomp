// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiSkinInstance; size 0x88
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CRITICAL_SECTION_9c93bfc5.h"
#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiSkinData_7f019f67.h"
#include "NiPointer_RE__NiSkinPartition_ee1aac44.h"
struct NiAVObject;
struct NiTransform;
struct NiSkinInstance {
    NiObject_de5bc370 _base;
    NiPointer_RE__NiSkinData_7f019f67 skinData;
    NiPointer_RE__NiSkinPartition_ee1aac44 skinPartition;
    NiAVObject* rootParent;
    NiAVObject** bones;
    NiTransform** boneWorldTransforms;
    unsigned int frameID;
    unsigned int numMatrices;
    unsigned int numRegisters;
    unsigned int allocatedSize;
    void* boneMatrices;
    void* prevBoneMatrices;
    void* skinToWorldWorldToSkinMatrix;
    CRITICAL_SECTION_9c93bfc5 lock;
};
static_assert(sizeof(NiSkinInstance) == 136, "NiSkinInstance layout differs from the PDB");
