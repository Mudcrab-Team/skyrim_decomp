// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GarbageCollection; size 0xe8
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539.h"
#include "BSTArray_RE__BSTSmartPointer_RE__BipedAnim_4c478a85.h"
#include "BSTArray_RE__BSTSmartPointer_RE__NavMesh_d0833e53.h"
#include "BSTArray_RE__NiPointer_RE__BSCloneReserver_c542d9be.h"
#include "BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "BSTArray_RE__NiPointer_RE__QueuedFile_fd5f0264.h"
#include "BSTArray_RE__TESBoundObject_a9e5ca4f.h"
struct GarbageCollection {
    BSSpinLock lock;
    BSTArray_RE__BSTSmartPointer_RE__BSAnimationGraphManager_a3451539 animations;
    BSTArray_RE__TESBoundObject_a9e5ca4f baseObjects;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 objectHandles;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 actorNodes;
    BSTArray_RE__BSTSmartPointer_RE__BipedAnim_4c478a85 bipedAnims;
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d tempEffects;
    BSTArray_RE__NiPointer_RE__QueuedFile_fd5f0264 queuedFiles;
    BSTArray_RE__NiPointer_RE__BSCloneReserver_c542d9be cloneReservers;
    BSTArray_RE__BSTSmartPointer_RE__NavMesh_d0833e53 navMeshes;
    bool deleting;
    unsigned char undefined_e1[7];
};
static_assert(sizeof(GarbageCollection) == 232, "GarbageCollection layout differs from the PDB");
