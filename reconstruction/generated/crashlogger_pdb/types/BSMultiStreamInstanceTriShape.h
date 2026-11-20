// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiStreamInstanceTriShape; size 0x1a0
#pragma once

#include "BSInstanceTriShape.h"
#include "BSTArray_RE__BSMultiStreamInstanceTriShape__InstanceGroup_94b6886b.h"
struct BSMultiStreamInstanceTriShape {
    BSInstanceTriShape _base;
    BSTArray_RE__BSMultiStreamInstanceTriShape__InstanceGroup_94b6886b instanceGroups;
    unsigned int meshTriCount;
    unsigned int maxInstancesPerGroup;
    float renderDistance;
    unsigned int unk184;
    void* groupAlloc;
    unsigned int instanceCount;
    unsigned int instanceSize;
    unsigned int activeGroupCount;
    unsigned char undefined_19c[4];
};
static_assert(sizeof(BSMultiStreamInstanceTriShape) == 416, "BSMultiStreamInstanceTriShape layout differs from the PDB");
